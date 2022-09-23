#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll P = 993244853;
ll Q[4] = {0, 998244353, 989899159, 989900669};

struct HSH {
	ll pw[4];
	ll xo;

	HSH() : xo(0) {
		pw[1] = pw[2] = pw[3] = 0;
	}
};

struct EVT {
	int x, v, t;
	EVT(int _x, int _v, int _t) : x(_x), v(_v), t(_t) {}
};

bool cmp1(EVT a, EVT b) {
	if(a.x == b.x) return a.t > b.t;
	return a.x < b.x;
}
bool cmp2(EVT a, EVT b) {
	if(a.x == b.x) return a.t > b.t;
	return a.x > b.x;
}

ll pw(ll a, ll b, ll mod) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

vector<EVT> v;

HSH LA[101010];
HSH LB[101010];
HSH RA[101010];
HSH RB[101010];
int N;

int SA[101010];
int SB[101010];
int EA[101010];
int EB[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d%d", &SA[i], &EA[i], &SB[i], &EB[i]);
	}

	for(int z = 0; z < 2; z++) {

	for(int i = 1; i <= N; i++) {
		if(z == 0) {
			v.push_back(EVT(SA[i], i, 1));
			v.push_back(EVT(EA[i], i, -1));
		}
		else {
			v.push_back(EVT(SB[i], i, 1));
			v.push_back(EVT(EB[i], i, -1));
		}
	}

	sort(v.begin(), v.end(), cmp1);

	HSH x;
	for(auto i : v) {
		if(i.t == -1) {
			for(int j = 1; j <= 3; j++) {
				x.pw[j] = (x.pw[j] + pw(P, i.v, Q[j])) % Q[j];
			}
			x.xo ^= i.v;
		}

		else {
			if(z == 0) LA[i.v] = x;
			else LB[i.v] = x;
		}
	}

	v.clear();
	for(int i = 1; i <= N; i++) {
		if(z == 0) {
			v.push_back(EVT(EA[i], i, 1));
			v.push_back(EVT(SA[i], i, -1));
		}
		else {
			v.push_back(EVT(EB[i], i, 1));
			v.push_back(EVT(SB[i], i, -1));
		}
	}

	sort(v.begin(), v.end(), cmp2);

	x = HSH();
	for(auto i : v) {
		if(i.t == -1) {
			for(int j = 1; j <= 3; j++) {
				x.pw[j] = (x.pw[j] + pw(P, i.v, Q[j])) % Q[j];
			}
			x.xo ^= i.v;
		}

		else {
			if(z == 0) RA[i.v] = x;
			else RB[i.v] = x;
		}
	}
	v.clear();

	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= 3; j++) {
			if((LA[i].pw[j] + RA[i].pw[j]) % Q[j] != (LB[i].pw[j] + RB[i].pw[j]) % Q[j]) { puts("NO"); return 0; }
		}
		if((LA[i].xo ^ RA[i].xo) != (LB[i].xo ^ RB[i].xo)) { puts("NO"); return 0; }
	}
	puts("YES");

	return 0;
}