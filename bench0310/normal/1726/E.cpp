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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<mi> f(n+1,1);
        for(int i=1;i<=n;i++) f[i]=f[i-1]*mi(i);
        vector<mi> finv(n+1,1); finv[n]=inv(f[n]);
        for(int i=n;i>=1;i--) finv[i-1]=finv[i]*mi(i);
        auto C=[&](int a,int b)->mi{return (f[a]*finv[b]*finv[a-b]);};
        vector<mi> fd(n+1,1);
        for(int i=2;i<=n;i++) fd[i]=fd[i-2]*mi(i);
        vector<mi> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++) dp[i]=dp[i-1]+mi(i-1)*dp[i-2];
        mi res=dp[n];
        for(int c=1;4*c<=n;c++)
        {
            int p=2*c;
            res+=(C(n-p,p)*pow(mi(2),p/2)*fd[p-1]*dp[n-4*c]);
        }
        cout << res << "\n";
    }
    return 0;
}