#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

const int MOD = 1000000007;

struct mat {
    int dat[5][5];
    mat() {
        F0R(i,5) F0R(j,5) dat[i][j] = MOD;
        F0R(i,5) dat[i][i] = 0;
    }
};

string s; 
int n,q;
mat seg[1<<19];

mat operator+(mat a, mat b) {
    mat c; F0R(i,5) c.dat[i][i] = MOD;
    F0R(i,5) F0R(j,5) F0R(k,5) c.dat[i][k] = min(c.dat[i][k],a.dat[i][j]+b.dat[j][k]);
    return c;
}

mat query(int ind, int lo, int hi, int L, int R) {
    if (R<lo || hi<L) return mat();
    if (L <= lo && hi <= R) return seg[ind];
    int mid = (lo+hi)/2;
    return query(2*ind,lo,mid,L,R)+query(2*ind+1,mid+1,hi,L,R);
}

int main() {
	cin >> n >> q >> s;
	string t = "2017";
	F0R(i,s.length()) {
	    int i1 = i+(1<<18);
	    F0R(j,4) if (t[j] == s[i]) seg[i1].dat[j][j] = 1, seg[i1].dat[j][j+1] = 0;
	    if (s[i] == '6') seg[i1].dat[3][3] = seg[i1].dat[4][4] = 1;
	}
	for (int i = (1<<18)-1; i > 0; --i) seg[i] = seg[2*i]+seg[2*i+1];
	F0R(i,q) {
		int a,b; cin >> a >> b;
		a--, b--;
		auto m = query(1,0,(1<<18)-1,a,b);
		if (m.dat[0][4] == MOD) cout << "-1\n";
		else cout << m.dat[0][4] << "\n";
	}
}