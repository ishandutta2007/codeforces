#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;

ll pw[1010101];

int N, M, Q;
int X[1010101][2];
int Y[1010101][2];
int cntX[4];
int cntY[4];
int C[2];
map<pii, int> mp;

int getX(int x) {
	int a = !!(X[x][0]), b = !!(X[x][1]);
	return a << 1 | b;
}

int getY(int y) {
	int a = !!(Y[y][0]), b = !!(Y[y][1]);
	return a << 1 | b;
}

void ers(int x, int y) {
	int t = mp[{x, y}];
	mp.erase({x, y});

	cntX[getX(x)]--;
	X[x][y & 1 ^ t]--;
	cntX[getX(x)]++;

	cntY[getY(y)]--;
	Y[y][x & 1 ^ t]--;
	cntY[getY(y)]++;

	C[x & 1 ^ y & 1 ^ t]--;
}

void add(int x, int y, int t) {
	mp[{x, y}] = t;

	cntX[getX(x)]--;
	X[x][y & 1 ^ t]++;
	cntX[getX(x)]++;

	cntY[getY(y)]--;
	Y[y][x & 1 ^ t]++;
	cntY[getY(y)]++;

	C[x & 1 ^ y & 1 ^ t]++;
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	pw[0] = 1;
	for(int i = 1; i <= max(N, M); i++) pw[i] = pw[i - 1] * 2 % MOD;
	cntX[0] = N; cntY[0] = M;

	while(Q--) {
		int x, y, t; scanf("%d%d%d", &x, &y, &t);
		if(t == -1) {
			if(mp.find({x, y}) != mp.end()) ers(x, y);
		}
		else {
			if(mp.find({x, y}) != mp.end()) ers(x, y);
			add(x, y, t);
		}

		ll ans = 0;
		if(!cntX[3]) {
			ans = (ans + pw[cntX[0]]) % MOD;
		}
		if(!cntY[3]) {
			ans = (ans + pw[cntY[0]]) % MOD;
		}

		ans = (ans + MOD - !(C[0])) % MOD;
		ans = (ans + MOD - !(C[1])) % MOD;

		printf("%lld\n", ans);
	}

	return 0;
}