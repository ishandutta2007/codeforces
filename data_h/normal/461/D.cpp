#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 111111;
const int MOD = 1e9 + 7;

int n, q;
int father[N], value[N];
pair<pair<int, int>, char> pairs[N];
int number[N];

int find(int x) {
	if (father[x] == x) {
		return x;
	}
	int temp = find(father[x]);
	value[x] ^= value[father[x]];
	father[x] = temp;
	return temp;
}

void getSec(int &lower, int &upper, pair<int, int> pos) {
	upper = n - 1, lower = 0;
	int x = pos.first, y = pos.second;
	upper = min(upper, x + y);
	upper = min(upper, 2 * (n - 1) - x - y);
	lower = max(lower, abs(x - y));
	
	if (lower % 2 != (x + y) % 2) {
		lower++;
	}
	
	if (upper % 2 != (x + y) % 2) {
		upper--;
	}
}

bool refresh(int l, int r, int v) {
	if (l > r) {
		if (v) {
			return false;
		} else {
			return true;
		}
	}
	
	l = number[l] - 1;
	r = number[r];
	
	//printf("link %d %d %d\n", l, r, v);
	
	if (find(l) == find(r)) {
		if (value[l] ^ value[r] != v) {
			return false;
		}
	} else {
		v ^= value[r];
		r = father[r];
		
		v ^= value[l];
		l = father[l];
		
		father[r] = l;
		value[r] = v;
	}
	
	return true;
}

int solve(int mod) {
	int tot = 0;
	for(int i = 0; i < n; i++) {
		if (i % 2 == mod) {
			number[i] = ++tot;
		}
	}	
	for(int i = 0; i <= tot; ++i) {
		father[i] = i;
		value[i] = 0;
	}
	
	int l, r;
	for(int i = 1; i <= q; i++) {
		if ((pairs[i].first.first + pairs[i].first.second) % 2 == mod) {
			getSec(l, r, pairs[i].first);
			if (!refresh(l, r, pairs[i].second == 'o')) {
				return 0;
			}
		}
	}
	
	int answer = 1, first = 1;
	for(int i = 0; i <= tot; i++) {
		if (find(i) == i) {
			if (!first) {
				(answer *= 2) %= MOD;
			} else {
				first = 0;
			}
		}
	}
	
	//cerr << mod << " " << answer << endl;
	
	return answer;
}

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= q; i++) {
		int x, y;
		static char buf[N];
		scanf("%d %d %s", &x, &y, buf);
		x--; y--;
		pairs[i] = make_pair(make_pair(x, y), buf[0]);
	}
	
	printf("%d\n", 1LL * solve(0) * solve(1) % MOD);
	return 0;
}