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
const ll INF=(ll)2e18;
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
const int N=100005;
const int B=1300;
int n; 
int e=0,first[N],nxt[N<<1],point[N<<1];
vector<int> v[N];
void add_edge(int x,int y){
    nxt[e]=first[x]; point[e]=y; first[x]=e++;
}

int dfn[N],dfn_clock=0;
void dfs0(int u,int f){
    dfn[++dfn_clock]=u;
    for(auto &to : v[u]) if(to!=f){
        add_edge(u,to);
        dfs0(to,u);
    }
}

int dp[N],mx[N],k;
void dfs(){
    for(int i=n;i>=1;i--){
        int u=dfn[i];
        int mx1=0,mx2=0;
        dp[u]=0,mx[u]=0;
        for(int i=first[u];i!=-1;i=nxt[i]){
            int to=point[i];
            dp[u]+=dp[to];
            if(mx1<mx[to]) mx2=mx1,mx1=mx[to];
            else if(mx2<mx[to]) mx2=mx[to];
        }
        if(mx1+mx2+1>=k) dp[u]++;
        else mx[u]=mx1+1;
    }
}

int ans[N],cnt=0;
int run(int k){
    cnt++; ::k=k;
    if(ans[k]) return ans[k];
    dfs();
    return ans[k]=dp[1];
}
int main()
{
    memset(first,-1,sizeof(first));
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs0(1,-1);
    for(int i=1;i<=min(n,B);i++) run(i);
    if(B<n){
        int now=ans[B],pos=B;
        for(;now;now--){
            int l=pos+1,r=n,mid,best=pos;
            while(l<=r){
                mid=(l+r)>>1;
                if(run(mid)==now) l=mid+1,best=mid;
                else r=mid-1;
            }
            pos=best+1;
        }
    }
    outln(cnt);
    for(int i=n;i>=1;i--) checkmax(ans[i],ans[i+1]);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}