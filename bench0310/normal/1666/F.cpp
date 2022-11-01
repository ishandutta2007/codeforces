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
        vector c(n+1,vector(n+1,mi(0)));
        for(int i=0;i<=n;i++) c[i][0]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
        vector<int> cnt(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            cnt[a]++;
        }
        vector<mi> dp(n/2+1,0);
        dp[0]=1;
        int s=0;
        for(int i=n;i>=1;i--)
        {
            vector<mi> ndp(n/2+1,0);
            for(int u=0;u<=n/2;u++)
            {
                int d=s-u;
                int f=max(0,u-d-1+(u==n/2));
                for(int j=0;j<=min({1,cnt[i],n/2-u});j++) if(cnt[i]-j<=f) ndp[u+j]+=(dp[u]*c[f][cnt[i]-j]);
            }
            s+=cnt[i];
            dp=ndp;
        }
        cout << dp[n/2] << "\n";
    }
    return 0;
}