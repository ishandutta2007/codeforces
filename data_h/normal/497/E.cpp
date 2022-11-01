#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int K = 30;
const int MOD = 1e9 + 7;

long long n, power[K + 1];
int k;

__inline void add(int &a, int b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
}

struct Matrix {
	int trans[K][K];
	int go[K];
	Matrix() {
		memset(trans, 0, sizeof(trans));
		memset(go, 0, sizeof(go));
	}
	int all() {
		int result = 0;
		for(int i = 0; i < k; i++) {
			add(result, go[i]);
			for(int j = 0; j < k; j++) {
				add(result, trans[i][j]);
			}
		}
		return result;
	}
};

map<long long, Matrix> mp;

Matrix search(long long n) {
	if (mp.count(n)) {
		return mp[n];
	}
	//cout << n << endl;

	Matrix ret;
	if (k >= n) {
		for(int i = 0; i < n; i++) {
			ret.go[i] = 0;
			ret.trans[i][i] = 1;
			for(int j = i + 1; j < n; j++) {
				ret.trans[i][j] = power[j - i - 1];
			}
		}
		return ret;
	}
	long long unit = 1;
	int length = 1;
	while(unit <= n / k && unit * k < n) {
		unit *= k;
		length++;
	}

	Matrix base = search(unit);
	ret = base;
	long long remaind = n % unit;
	Matrix extra = search(remaind);

	static int reach[K][K], _reach[K][K];
	for(int i = 0; i < k; i++) {
		ret.go[i] = base.go[i];
		for(int j = 0; j < k; j++) {
			reach[i][j] = base.trans[i][j];
		}
	}
/*
cout << "n = " << n << endl;

for(int i = 0; i < k; i++) {
	for(int j = 0; j < k; j++) {
		cout << reach[i][j] << " ";
	}
	cout << endl;
}


cout << "-----" << endl;
for(int i = 0; i < k; i++) {
	cout << "go[" << i << "] = " << ret.go[i] << endl;
}
cout << endl;
*/
	for(int i = 1; i <= n / unit; i++) {
		if (i == n / unit && remaind == 0) {
			break;
		}
		Matrix &nxt = (i < n / unit) ? base : extra;
		int lead = i;
		for(int j = 0; j < k; j++) {
			for(int l = 0; l < k; l++) {
				_reach[j][l] = reach[j][l];
				add(ret.go[j], reach[j][l]);
				reach[j][l] = 0;
			}
		}

		int t = ((k - 1) * (length - 2) + i - 1) % k;
//cout << "t = " << t << endl;
		for(int start = 0; start < k; start++) {
			int sum = 0;
			for(int prev = k - 1; prev >= 0; prev--) {
				int pv = (prev + t) % k;
				/*
				if (_reach[start][pv] == 0) {
					continue;
				}*/
				add(sum, _reach[start][pv]);
				//for(int succ = 0; succ <= prev; succ++) {
					int succ = prev;
					int sv = (succ + t) % k, temp = ((sv - i) % k + k) % k;
					add(ret.go[start], 1LL * sum * nxt.go[temp] % MOD);
					for(int end = 0; end < k; end++) {
						/*if (start == 0 && end == 1) {
							printf("%d %d %d %d %d %d\n", start, pv, sv - i + k, end - i + k)
						}*/
						add(reach[start][end], 1LL * sum * nxt.trans[temp][((end - i) % k + k) % k] % MOD);
					}
				//}
			}
		}

for(int i = 0; i < k; i++) {
	for(int j = 0; j < k; j++) {
		ret.trans[i][j] = reach[i][j];
//		cout << reach[i][j] << " ";
	}
//	cout << endl;
}
/*cout << "-----" << endl;
for(int i = 0; i < k; i++) {
	cout << "go[" << i << "] = " << ret.go[i] << endl;
}
cout << endl;
*/
	}
	return mp[n] = ret;
}

int main() {
	power[0] = 1;
	for(int i = 1; i <= K; i++) {
		power[i] = power[i - 1] * 2;
	}
	cin >> n >> k;
	Matrix answer = search(n);
	cout << (answer.all() + 1) % MOD << endl;
	return 0;
}