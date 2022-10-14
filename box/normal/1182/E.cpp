// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;
const int ph = 1000000006;

template<typename T>
struct mat {
	T dat[5][5];
	void init() { rep(i, 5) rep(j, 5) dat[i][j] = 0; }
	T* operator[](int a) { return dat[a]; }
	T const* operator[](int a) const { return dat[a]; }
};

using matt=mat<ll>;

matt mult(const matt&a, const matt&b) {
	matt ans; ans.init();
	rep(i, 5) rep(j, 5) rep(k, 5) ans[i][k]=(ans[i][k]+a[i][j]*b[j][k])%ph;
	return ans;
}

matt qpow(const matt& b, const ll&e) {
	if(e==1) return b;
	if(!(e&1)) return qpow(mult(b,b),e>>1);
	return mult(qpow(b,e-1),b);
}

ll qpow(const ll&b, const ll&e) {
	if(!e) return 1;
	if(!(e&1)) return qpow(b*b%MOD,e>>1);
	return b*qpow(b,e-1)%MOD;
}

ll a(ll n, int k) {
	if(n==1) return 1;
	if(n==2) return 0;
	if(n==3) return 0;
	matt v; v.init();
	v[0][0] = 1; v[0][1] = 1; v[0][2] = 1; v[1][0] = 1; v[2][1] = 1;
	v = qpow(v, n-3);
	matt i; i.init();
	i[2-k][0] = 1;
	return mult(v, i)[0][0];
}

ll d(ll n) {
	if(n==1) return 0;
	if(n==2) return 0;
	if(n==3) return 0;
	matt v; v.init();
	v[0][0] = 1; v[0][1] = 1; v[0][2] = 1; v[0][3] = 1;
	v[1][0] = 1; v[2][1] = 1; v[3][3] = 1; v[3][4] = 1; v[4][4] = 1;
	v = qpow(v, n-3);
	matt i; i.init();
	i[3][0] = 2; i[4][0] = 2;
	return mult(v, i)[0][0];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, f1, f2, f3, c; cin >> n >> f1 >> f2 >> f3 >> c;
	cout << qpow(f1,a(n,0))*qpow(f2,a(n,1))%MOD*qpow(f3,a(n,2))%MOD*qpow(c,d(n))%MOD << endl;
}