#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MN = 1e6+3;
using ll = long long;
struct modint {
    int v;
    modint() {v=0;}
    modint (ll _v) {v = _v%MOD; if(v<0)v+=MOD;}
    modint (int _v) {v=_v; if(v<0)v+=MOD;}
    friend void scan (modint &a) {scanf("%d",&a.v);if(a.v>=MOD)a.v-=MOD;}
    friend void scanll(modint &a){ll r;scanf("%lld",&r);a.v=r%MOD;if(a.v<0)a.v+=MOD;}
    friend void print (const modint &a) {printf("%d",a.v);}
    friend void print (const modint &a, const char &c) {printf ("%d%c",a.v,c);}
    void operator= (const modint &m) {v = m.v;}
    void operator= (const int &_v) {*this = modint(_v);}
    void operator= (const ll &_v) {*this = modint(_v);}
    friend modint fpow (modint base, int ex) {modint res = 1;while (ex){if (ex&1) res*=base;base*=base;ex>>=1;}return res;}
    friend modint fpow (modint base, ll ex) {modint res = 1;while (ex){if (ex&1) res*=base;base*=base;ex>>=1;}return res;}
    friend modint inv (modint a) {return fpow(a,MOD-2);}
    friend modint inv (int a) {return fpow(modint(a),MOD-2);}
    modint operator+= (const int &_v) {v+=_v;if(v>=MOD)v-=MOD;return v;}
    modint operator-= (const int &_v) {v-=_v;if(v<0)v+=MOD;return v;}
    modint operator*= (const int &_v) {v=(ll)v*_v%MOD;if(v<0)v+=MOD;return v;}
    modint operator/= (const int &_v) {return (*this)*=inv(modint(_v));}
    modint operator+= (const modint &m) {return (*this)+=m.v;}
    modint operator-= (const modint &m) {return (*this)-=m.v;}
    modint operator*= (const modint &m) {return (*this)*=m.v;}
    modint operator/= (const modint &m) {return (*this)*=inv(m);}
    modint operator++ () {return (*this)+=1;}
    modint operator-- () {return (*this)-=1;}
    modint operator++ (int) {(*this)+=1;return (*this)-1;}
    modint operator-- (int) {(*this)-=1;return (*this)+1;}
    friend modint operator+ (modint m, const modint &m2) {return m+=m2;}
    friend modint operator- (modint m, const modint &m2) {return m-=m2;}
    friend modint operator* (modint m, const modint &m2) {return m*=m2;}
    friend modint operator/ (modint m, const modint &m2) {return m/=m2;}
    bool operator< (const modint &m) {return v < m.v;}
    bool operator< (const int &_v) {return v < _v;}
    bool operator> (const modint &m) {return v > m.v;}
    bool operator> (const int &_v) {return v > _v;}
    bool operator<= (const modint &m) {return v <= m.v;}
    bool operator<= (const int &_v) {return v <= _v;}
    bool operator>= (const modint &m) {return v >= m.v;}
    bool operator>= (const int &_v) {return v >= _v;}
    bool operator== (const modint &m) {return v == m.v;}
    bool operator== (const int &_v) {return v == _v;}
    bool operator!= (const modint &m) {return v != m.v;}
    bool operator!= (const int &_v) {return v != _v;}
};
#define all(x) (x).begin(),(x).end()
vector<vector<modint>> bit; int sz;
void update (int k, int i, modint v) {
	for(;i<=sz;i+=i&-i)
		bit[k][i] += v;
}
modint query (int k, int i) {
	modint ret = 0;
	for(;i;i^=i&-i)
		ret += bit[k][i];
	return ret;
}
vector<int> xs;
void getx (int &x) {x = lower_bound(all(xs),x)-xs.begin()+1;}
int main () {
	int n,K; ll l;
	scanf ("%d %lld %d",&n,&l,&K);
	vector<vector<modint>> dp(K+1,vector<modint>(n+1));
	bit.resize(K+1,vector<modint>(n+5));
	vector<int> a(n+1);
	modint ans = l;
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), dp[1][i] = 1, xs.push_back(a[i]);
	sort(all(xs)); sz = xs.size();
	for (int i = 1; i <= n; i++) getx(a[i]), update(1,a[i],1);
	for (int k = 2; k <= K; k++) {
		for (int i = 1; i <= n; i++) {
			dp[k][i] += query(k-1,a[i]);
			update(k,a[i],dp[k][i]);
			ans += dp[k][i] * (int)(max(0LL,l/n-k+1+(i<=l%n))%MOD);
		}
	}
	printf ("%d\n",ans);
    return 0;
}