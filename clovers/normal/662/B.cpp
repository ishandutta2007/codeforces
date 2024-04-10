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
const int N=100005;
int n,m,vis[N],col[N];
vector<pii> v[N];
int ans=inf; vector<int> ret;
int cnt=0; vector<int> used;
void dfs(int u){
    vis[u]=1; cnt+=col[u];
    used.push_back(u);
    for(auto &e : v[u]){
        int to=e.first,w=e.second;
        if(vis[to]){
            if(col[to]^col[u]!=w) cnt=inf;
            continue;
        }
        col[to]=col[u]^w;
        dfs(to);
    }
}
void solve(){
    memset(vis,0,sizeof(vis));
    vector<int> t;
    int sum=0;
    for(int i=1;i<=n;i++) if(!vis[i]){
        cnt=0; col[i]=0; used.clear();
        dfs(i); int ret1=cnt;
        for(auto &u : used) vis[u]=0;
        cnt=0; col[i]=1; used.clear();
        dfs(i); int ret2=cnt;
        if(ret1>=inf&&ret2>=inf) return;
        if(ret1<ret2){
            for(auto &u : used) if(!col[u]) t.push_back(u);
            sum+=ret1;
        }
        else{
            for(auto &u : used) if(col[u]) t.push_back(u);
            sum+=ret2;
        }
    }
    if(sum<ans) ans=sum,ret=t;
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(); char s[2];
        scanf("%s",s);
        int c=(s[0]=='B' ? 1 : 0);
        v[x].push_back(mk(y,c)); v[y].push_back(mk(x,c));
    }
    solve();
    for(int i=1;i<=n;i++){
        for(auto &e : v[i]) e.second^=1;
    }
    solve();
    if(ans>n) puts("-1");
    else{
        cout<<ans<<endl;
        for(auto &u : ret) printf("%d ",u); 
    }
    return 0;
}