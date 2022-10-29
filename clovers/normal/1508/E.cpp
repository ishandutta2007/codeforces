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
const int N=300005;
int n,a[N],dfn[N],fin[N],b[N],id[N],out[N],dep[N],pos[N];
ll ans=0;
vector<int> v[N];
bool cmp(int x,int y){return a[x]<a[y];}
int tot1=0,tot2=0,now=1;
void dfs1(int u,int f){
    dfn[u]=++tot1; id[tot1]=u;
    vector<int> tmp;
    for(auto &to : v[u]) if(to!=f) tmp.push_back(to);
    sort(tmp.begin(),tmp.end(),cmp); v[u]=tmp;
    for(auto &to : v[u]) dep[to]=dep[u]+1,dfs1(to,u);
    fin[u]=++tot2; out[u]=tot1;
    if(a[u]<now) ans+=dep[u];
}
bool isfa(int x,int y){return dfn[x]<=dfn[y]&&out[x]>=out[y];}
void Win(){
    puts("YES");
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",dfn[i]);
    exit(0);
}
void Lose(){puts("NO"); exit(0);}
int tot=0,P[N];
void dfs2(int u){
    if(!b[u]) b[u]=++tot;
    for(auto &to : v[u]) dfs2(to);
}

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    now=max(1,a[1]-1);
    dfs1(1,-1);
    if(now==n+1) Win();
    for(int i=1;i<=n;i++) if(fin[i]<now) b[i]=fin[i];
    tot=now-1;
    dfs2(1);
    for(int i=1;i<=n;i++) P[b[i]]=i;
    while(P[now]!=pos[now]){
        int flag=0;
        for(auto &to : v[P[now]]) if(b[to]>now){
            swap(b[P[now]],b[to]);
            P[now]=to; flag=1;
            break;
        }
        ans++;
        if(!flag) Lose();
    }
    for(int i=1;i<=n;i++) if(b[i]!=a[i]) Lose();
    Win();
    return 0;
}