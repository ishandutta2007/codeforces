#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=1000000007;

struct mi
{
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=(ll(v)*m.v)%mod; return *this;}
    mi& operator/=(const mi &m){return (*this)*=inv(m);}
    friend mi pow(mi a,ll e){mi r=1; for(;e;a*=a,e/=2)if(e&1)r*=a; return r;}
    friend mi inv(mi a){return pow(a,mod-2);}
    mi operator-()const{return mi(-v);}
    mi& operator++(){return (*this)+=1;}
    mi& operator--(){return (*this)-=1;}
    friend mi operator++(mi &a,int){mi t=a; ++a; return t;}
    friend mi operator--(mi &a,int){mi t=a; --a; return t;}
    friend mi operator+(mi a,const mi &b){return a+=b;}
    friend mi operator-(mi a,const mi &b){return a-=b;}
    friend mi operator*(mi a,const mi &b){return a*=b;}
    friend mi operator/(mi a,const mi &b){return a/=b;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        mi k;
        cin >> n >> m >> k;
        vector<mi> f(n+1,1);
        for(int i=1;i<=n;i++) f[i]=f[i-1]*mi(i);
        vector<mi> finv(n+1,1); finv[n]=inv(f[n]);
        for(int i=n;i>=1;i--) finv[i-1]=finv[i]*mi(i);
        auto c=[&](int a,int b)->mi
        {
            if(a<b) return 0;
            return (f[a]*finv[b]*finv[a-b]);
        };
        vector<mi> itwo(n+1,1);
        mi invtwo=inv(mi(2));
        for(int i=1;i<=n;i++) itwo[i]=itwo[i-1]*invtwo;
        mi res=0;
        for(int i=1;i<=m;i++) res+=(c(n-i-1,m-i)*mi(i)*itwo[n-i]);
        if(n==m) res+=n;
        cout << res*k << "\n";
    }
    return 0;
}