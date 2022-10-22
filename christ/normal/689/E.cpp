#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
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
    modint operator+= (const int &_v) {v+=_v;if(v>=MOD)v-=MOD;return *this;}
    modint operator-= (const int &_v) {v-=_v;if(v<0)v+=MOD;return *this;}
    modint operator*= (const int &_v) {v=(ll)v*_v%MOD;if(v<0)v+=MOD;return *this;}
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
modint fct[1000005];
modint fpow (int base, int exp) {return fpow(modint(base),exp);}
void initc (int n) {fct[0]=1;for (int i=1;i<=n;i++)fct[i]=fct[i-1]*i;}
modint fac (modint i) {return fct[i.v];}
modint fac (int i) {return fct[i];}
modint choose(modint n, modint k) {return fac(n)/(fac(k)*fac(n-k));}
modint permute (modint n, modint k) {return fac(n)/fac(n-k);}
struct Event {
	int time; int go;
	bool operator< (const Event &o) const {
		return time < o.time;
	}
};
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	initc(n);
	vector<Event> events(n<<1);
	for (int i = 0; i < n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		events[i<<1] = {a,1}; events[i<<1|1] = {b+1,-1};
	}
	sort(all(events));
	int cur = events[0].go; modint ret = 0;
	for (int i = 1; i < (n << 1); i++) {
		int dist = events[i].time-events[i-1].time;
		if (cur >= k && dist) ret += choose(cur,k) * dist;
		cur += events[i].go;
	}
	printf ("%d\n",ret);
    return 0;
}