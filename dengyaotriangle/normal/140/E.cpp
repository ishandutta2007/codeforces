#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1000005;
const int maxm=5005;

int n,m,t,mdn;

struct mint{
    int v;
    inline operator int()const{return v;}
    inline mint(int v=0):v(v){}
    inline bool operator==(const mint&a)const{return v==a.v;}
    inline bool operator!=(const mint&a)const{return v!=a.v;}
    inline mint operator- ()const{return mint(v==0?0:mdn-v);}
    inline mint operator+ (const mint&a)const{mint c(v+a.v);if(c.v>=mdn)c.v-=mdn;return c;}
    inline mint operator- (const mint&a)const{mint c(v-a.v);if(c.v<0)c.v+=mdn;return c;}
    inline mint operator* (const mint&a)const{long long c=static_cast<long long>(v)*static_cast<long long>(a.v);return mint(c%mdn);}
    inline mint&operator+=(const mint&a){v+=a.v;if(v>=mdn)v-=mdn;return*this;}
    inline mint&operator-=(const mint&a){v-=a.v;if(v<0)v+=mdn;return*this;}
    inline mint&operator*=(const mint&a){long long c=static_cast<long long>(v)*static_cast<long long>(a.v);v=c%mdn;return*this;}
    friend istream&operator>>(istream&s,mint&a){s>>a.v;return s;}
    friend ostream&operator<<(ostream&s,const mint&a){s<<a.v;return s;}
};

int l[maxn];
mint dp0[maxm][maxm];
mint fac[maxn];
mint c[maxn];
mint dp[2][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>mdn;
    for(int i=1;i<=n;i++){cin>>l[i];t=max(t,l[i]);}
    dp0[0][0]=1;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=i;j++){
            dp0[i][j]=dp0[i-1][j]*(mint)(j-1)+dp0[i-1][j-1];
        }
    }
    fac[0]=1;for(int i=1;i<=m;i++)fac[i]=fac[i-1]*(mint)i;
    c[0]=1;for(int i=1;i<=m;i++)c[i]=c[i-1]*(mint)(m-i+1);
    dp[0][0]=1;
    mint ans=0;
    for(int i=1;i<=n;i++){
        mint sum=0;
        for(int j=0;j<=l[i];j++)dp[i&1][j]=0;
        for(int j=0;j<=l[i-1];j++)sum+=dp[!(i&1)][j];
        for(int j=1;j<=l[i];j++){
            if(j<=l[i-1])dp[i&1][j]=dp0[l[i]][j]*(c[j]*sum-fac[j]*dp[!(i&1)][j]);
            else dp[i&1][j]=dp0[l[i]][j]*c[j]*sum;
            if(i==n)ans+=dp[i&1][j];
        }
    }
    cout<<ans;
    return 0;
}