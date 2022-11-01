#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;

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
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> s(n+2,0);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        int d;
        cin >> d;
        s[i+1]=s[i]+d;
        sum+=d;
    }
    int c=0;
    int r=1;
    for(int l=1;l<=n;l++)
    {
        while(r+1<=n&&s[r]-s[l]<sum/2) r++;
        c+=(((sum%2)==0)&&s[r]-s[l]==sum/2);
    }
    const int N=300000;
    vector<mi> f(N+1,1);
    for(int i=1;i<=N;i++) f[i]=f[i-1]*mi(i);
    vector<mi> finv(N+1,1); finv[N]=inv(f[N]);
    for(int i=N;i>=1;i--) finv[i-1]=finv[i]*mi(i);
    auto C=[&](int a,int b)->mi{return (f[a]*finv[b]*finv[a-b]);};
    mi res=0;
    for(int i=0;i<=c;i++)
    {
        if(i>m) continue;
        mi now=C(c,i)*C(m,i)*f[i];
        int a=(n-2*c);
        int b=(c-i);
        int col=(m-i);
        now*=pow(mi(col),a);
        now*=pow(mi(col)*mi(col-1),b);
        res+=now;
    }
    cout << res << "\n";
    return 0;
}