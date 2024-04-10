#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 11111;

int n;
int x[N], y[N], tot;
vector<pair<int, int> > answerx, answery;
int number[N], pos[N];

int getHigh(int x) {
	int res = -1;
	for(int i = 0; i < 32; i++) {
		if (x >> i & 1) {
			res = i;
		}
	} 
	return res;
}

void print(int x[], int i, int j, vector<pair<int, int> > &vec) {
	x[i] ^= x[j];
	vec.push_back(make_pair(i, j));
}

void sswap(int x[], int i, int j, vector<pair<int, int> > &vec) {
	if (i == j) {
		return ;
	}
	print(x, i, j, vec);
	print(x, j, i, vec);
	print(x, i, j, vec);
}

void solve(int x[], vector<pair<int, int> > &vec, int &tot) {
	tot = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= tot; j++) {
			if ((x[i] ^ x[j]) < x[i]) {
				print(x, i, j, vec);
			}
		}
		if (x[i] == 0) {
			continue;
		}
		int h = getHigh(x[i]), rank = 0;
		for(int j = 1; j <= tot; j++) {
			if (getHigh(x[j]) > h) {
				rank = j;
			}
		}
		sswap(x, ++tot, i, vec);
		for(int j = tot - 1; j > rank; j--) {
			sswap(x, j, j + 1, vec);
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &y[i]);
	}
	int totx, toty;
	solve(x, answerx, totx);
	solve(y, answery, toty);
	if (totx < toty) {
		printf("-1\n");
		return 0;
	}
	
	for(int i = 1; i <= toty; i++) {
		bool find = false;
		for(int j = i; j <= totx; j++) {
			if (getHigh(x[j]) == getHigh(y[i])) {
				find = true;
				sswap(x, i, j, answerx);
			}
		}
		if (!find) {
			printf("-1\n");
			return 0;
		}
		for(int m = 31; m >= 0; m--) {
			if ((x[i] >> m & 1) != (y[i] >> m & 1)) {
				bool find = false;
				for(int j = i + 1; j <= totx; j++) {
					if (getHigh(x[j]) == m) {
						find = true;
						print(x, i, j, answerx);
					}
				}
				if (!find) {
					printf("-1\n");
				}
			}
		}
	}
	totx = toty;
	for(int i = totx + 1; i <= n; i++) {
		print(x, i, i, answerx);
		print(y, i, i, answery);
	}
	for(int i = (int)answery.size() - 1; i >= 0; i--) {
		int a = answery[i].first, b = answery[i].second;
		print(x, a, b, answerx);
	}
	
	printf("%d\n", (int)answerx.size());
	for(int i = 0; i < (int)answerx.size(); i++) {
		printf("%d %d\n", answerx[i].first, answerx[i].second);
	}
	return 0;
}