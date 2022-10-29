#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
const int MOD=(int)1e9+7;
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int mul(int x,int y){return 1ll*x*y%MOD;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
vector<int> v[N];

int n,fa[N]; ll sum=0,a[N];
int qpow(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret=mul(ret,x);
        x=mul(x,x);
        y>>=1;
    }
    return ret;
}

int fac[N];
ll gcd(ll x,ll y){
    if(!y) return x;
    return gcd(y,x%y);
}

void dfs(int u){
    for(int i=0;i<(int)v[u].size();i++){
        int to=v[u][i]; if(to==fa[u]) continue;
        dfs(to); a[u]+=a[to];
    }
}
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
    for(int i=2;i<=n;i++) {
        scanf("%d",&fa[i]);
        v[fa[i]].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        ll g=sum/gcd(a[i],sum);
        for(ll j=g;j<=n;j+=g) fac[j]++;
    }
}

ll f[10005],cnt=0;
int dp[10005];
void solve(){
    for(int i=1;i<=n;i++) if(fac[i]==i) f[++cnt]=sum/i;
    sort(f+1,f+cnt+1);
    for(int i=1;i<=cnt;i++){
        dp[i]=add(dp[i],1);
        for(int j=i+1;j<=cnt;j++){
            if(f[j]%f[i]==0) dp[j]=add(dp[j],dp[i]);
        }
    }
    printf("%d\n",dp[cnt]);
}

int main(){
    init();
    solve();
    return 0;
}