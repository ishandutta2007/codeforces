#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n,m,k;
int x;
vector<int> v[3005];
long long dp[3005][3005];
long long c[3005][3005];
long long dp2[3005];
long long f[3005];

void dfs(int x) {
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        dfs(to);
    }
    for (int i=1;i<=k;++i)
        dp2[i]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        for (int j=1;j<=k;++j) {
            dp2[j]=(dp2[j]*dp[to][j])%md;
        }
    }
    for (int i=1;i<=k;++i) {
        dp2[i]+=dp2[i-1];
        if (dp2[i]>=md) dp2[i]-=md;
        dp[x][i]=dp2[i];
    }
}

inline long long pw(long long x,long long y) {
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}

inline long long getc(int x,int y) {
    long long res=1;
    for (int i=x;i>x-y;--i) {
        res*=i;
        res%=md;
    }
    res=(res*pw(f[y],md-2))%md;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    k=min(n,m);
    for (int i=2;i<=n;++i) {
        cin>>x;
        v[x].push_back(i);
    }
    dfs(1);
    c[0][0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=n;++j) {
            c[i][j]=c[i-1][j];
            if (j) {
                c[i][j]+=c[i-1][j-1];
                if (c[i][j]>=md) c[i][j]-=md;
            }
        }
    }
    long long cur;
    for (int i=1;i<=k;++i) {
        for (int j=i-1;j>0;--j) {
            cur=dp[1][j];
            cur*=c[i][j];
            cur%=md;
            dp[1][i]-=cur;
            if (dp[1][i]<0) dp[1][i]+=md;
        }
    }
    f[0]=1;
    for (int i=1;i<=k;++i)
        f[i]=(f[i-1]*1ll*i)%md;
    long long res=0;
    for (int i=1;i<=k;++i) {
        cur=getc(m,i);
        cur*=dp[1][i];
        cur%=md;
        res+=cur;
        if (res>=md) res-=md;
    }
    cout<<res;
}