#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int mod;

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
    cin >> n >> mod;
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector dp(n+1,vector(n,mi(0)));
    vector s(n+1,vector(n,mi(0)));
    function<void(int,int)> dfs=[&](int a,int p)
    {
        vector<int> ch={0};
        int c=0;
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            ch.push_back(to);
            c++;
        }
        vector d(n,vector(c+1,mi(0)));
        for(int j=1;j<n;j++)
        {
            vector<mi> pre(c+2,1);
            for(int k=1;k<=c;k++) pre[k]=(pre[k-1]*s[ch[k]][j]);
            vector<mi> suf(c+2,1);
            for(int k=c;k>=1;k--) suf[k]=(suf[k+1]*s[ch[k]][j]);
            for(int k=1;k<=c;k++) d[j][k]=(pre[k-1]*suf[k+1]);
        }
        if(a!=1)
        {
            for(int k=1;k<=c;k++)
            {
                mi sum=0;
                for(int i=1;i<n;i++)
                {
                    dp[a][i]+=(dp[ch[k]][i]*sum);
                    sum+=d[i][k];
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            mi t=1;
            for(int k=1;k<=c;k++) t*=s[ch[k]][i];
            dp[a][i]+=t;
        }
        for(int i=1;i<n;i++) s[a][i]=s[a][i-1]+dp[a][i];
    };
    dfs(1,0);
    vector C(n+1,vector(n+1,mi(0)));
    for(int i=0;i<=n;i++) C[i][0]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
    vector<mi> res(n,0);
    for(int i=1;i<n;i++)
    {
        res[i]=dp[1][i];
        for(int j=1;j<i;j++) res[i]-=(res[j]*C[i][j]);
        cout << res[i] << " \n"[i==n-1];
    }
    return 0;
}