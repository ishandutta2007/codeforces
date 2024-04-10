#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef bitset<500>* mat;
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

int x,r;
mat rec[2][61], cm;

mat make() {
	return new bitset<500>[x];
} 

mat mult(mat a, mat b) {
	mat res = make();
	F0R(i,x) F0R(k,x) if (a[i][k]) res[i] |= b[k];
	return res;
}

bool testok(mat a) {
	F0R(i,x) if (a[0][i]) return 1;
	return 0;
}

int main() {
	cin >> x >> r;
	rec[0][0] = make(); rec[1][0] = make();
	F0R(i,r) {
		int v,u,t; cin >> v >> u >> t;
		rec[t][0][v-1][u-1] = 1;
	}
	FOR(i,1,61) {
		rec[0][i] = mult(rec[0][i-1],rec[1][i-1]);
		rec[1][i] = mult(rec[1][i-1],rec[0][i-1]);
	}
	cm = make(); F0R(i,x) cm[i][i] = 1;
	ll cur = 0, mx = 60, z = 0;
	while (mx>-1) {
		mat temp = mult(cm,rec[z][mx]);
		if(testok(temp)) {
			z = 1-z;
			cur += (ll)1<<mx;
			cm = temp;
		}
		mx--;
	}
	if (cur>(ll)1000000000000000000) cout << -1;
	else cout << cur;
}