#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int mod=998244353;

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
    int n,m;
    cin >> n >> m >> mod;
    vector<mi> f(n+1,1);
    for(int i=1;i<=n;i++) f[i]=f[i-1]*mi(i);
    vector<mi> finv(n+1,1); finv[n]=inv(f[n]);
    for(int i=n-1;i>=1;i--) finv[i]=finv[i+1]*mi(i+1);
    auto c=[&](int a,int b)->mi
    {
        if(!(0<=b&&b<=a)) return 0;
        return (f[a]*finv[b]*finv[a-b]);
    };
    vector<mi> dp1(n+1,0);
    vector<mi> dp2(n+1,0);
    vector dp3(n+1,vector(n+1,mi(0)));
    vector dp4(n+1,vector(n+1,mi(0)));
    dp1[0]=1;
    for(int i=0;i<=n;i++) dp3[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp1[i]+=((i+1)*c(i-1,j-1)*dp1[j-1]*dp1[i-j]);
            dp2[i]+=((i+1)*c(i-1,j-1)*(dp1[j-1]*dp2[i-j]+dp1[i-j]*dp2[j-1])+(c(j,2)+c(i-j+1,2))*c(i-1,j-1)*dp1[j-1]*dp1[i-j]);
            dp3[i][j]=dp3[i-1][j];
            dp4[i][j]=dp4[i-1][j];
            for(int k=1;k<=j;k++)
            {
                dp3[i][j]+=(dp1[k]*dp3[max(i-k-1,0)][j-k]*c(j,k));
                dp4[i][j]+=(dp1[k]*c(j,k)*dp4[max(i-k-1,0)][j-k]+dp3[max(i-k-1,0)][j-k]*c(j,k)*dp2[k]);
            }
        }
    }
    cout << dp4[n][m] << "\n";
    return 0;
}