#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
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
modint fct[1000005];
modint fpow (int base, int exp) {return fpow(modint(base),exp);}
void initc (int n) {fct[0]=1;for (int i=1;i<=n;i++)fct[i]=fct[i-1]*i;}
modint fac (modint i) {return fct[i.v];}
modint fac (int i) {return fct[i];}
modint choose(modint n, modint k) {return fac(n)/(fac(k)*fac(n-k));}
modint permute (modint n, modint k) {return fac(n)/fac(n-k);}
int main () {
    int n,k;
    scanf ("%d %d",&n,&k);
    initc(n);
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        b[i%n+1] = a[i];
    }
    int diff=0,same=0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) ++same;
        else ++diff;
    }
    modint ans = 0;
    for (int x = 1; x <= diff; ++x) {
        modint bruh = fpow(2,x-1);
        if (!(x&1)) bruh-=choose(x,x/2)/2;
        ans += fpow(max(0,k-2),diff-x)*choose(diff,x)*bruh;
    }
    printf ("%d\n",ans*fpow(k,same));
    return 0;
}