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
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector c(n+1,vector(n+1,mi(0)));
    for(int i=0;i<=n;i++) c[i][0]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
    auto go=[&](ll r,ll z)->mi
    {
        vector<array<mi,2>> dp(n+1,{mi(0),mi(0)});
        dp[0][0]=1;
        for(int i=0;i<60;i++)
        {
            vector<array<mi,2>> ndp(n+1,{mi(0),mi(0)});
            for(int j=0;j<=n;j++)
            {
                for(int s=0;s<=1;s++)
                {
                    for(int k=((z>>i)&1);k<=n;k+=2)
                    {
                        int nj=(j+k)/2;
                        int b=(j+k)&1;
                        int a=(r>>i)&1;
                        int ns=((b<a?0:(b==a?s:1)));
                        ndp[nj][ns]+=(dp[j][s]*c[n][k]);
                    }
                }
            }
            dp=ndp;
        }
        return dp[0][0];
    };
    ll l,r,z;
    cin >> l >> r >> z;
    cout << go(r,z)-go(l-1,z) << "\n";
    return 0;
}