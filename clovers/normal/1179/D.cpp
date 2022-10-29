/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=500005;
int n,sz[N];
vector<int> v[N];
ll ans=0,dp[N],ret=INF;
void dfs1(int u,int f){
    sz[u]=1;
    for(auto &to : v[u]) if(to!=f) dfs1(to,u),sz[u]+=sz[to];
}
bool cmp(int x,int y){return sz[x]>sz[y];}
typedef pair<ll,ll> pll;
pll a[N]; int top=0;
double fk(pll x,pll y){
    return 1.0*(y.second-x.second)/(y.first-x.first);
}
int find(int k){
    int l=1,r=top-1,mid,best=top;
    while(l<=r){
        mid=(l+r)>>1;
        if(fk(a[mid],a[mid+1])>=k) best=mid,r=mid-1;
        else l=mid+1;
    }
    return best;
}
void dfs2(int u,int f){
    dp[u]=1ll*sz[u]*sz[u];
    for(auto &to : v[u]){
        if(to==f) continue;
        dfs2(to,u);
        checkmin(dp[u],dp[to]+1ll*(sz[u]-sz[to])*(sz[u]-sz[to]));
        checkmin(ret,dp[to]+1ll*(n-sz[to])*(n-sz[to]));
    }
    sort(v[u].begin(),v[u].end(),cmp);
    top=0; 
    for(auto &i : v[u]){
        if(i==f) continue;
        if(top){
            int pos=find(2*sz[i]);
            checkmin(ret,dp[i]+a[pos].second-2ll*sz[i]*a[pos].first+1ll*sz[i]*sz[i]);
        }
        ll x=n-sz[i],y=dp[i]+1ll*x*x;
        pii now=mk(x,y);
        while(top>=2&&fk(a[top],now)<=fk(a[top-1],a[top])&&x!=a[top].first) top--;
        while(top&&a[top].second>=y) top--;
        if(x!=a[top].first) a[++top]=mk(x,y);
    }
}

int main()
{
    n=read(); 
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs1(1,-1); ans=1ll*n*(n-1)/2;
    dfs2(1,-1);
    cout<<ans+(1ll*n*n-ret)/2<<endl;
    return 0;
}