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
const int N=200005;
int n,m,po[N],vis[N];
vector<int> v[N],G[N];

void dfs(int u){
    vis[u]=1;
    for(auto &to : v[u]){
        if(!vis[to]) dfs(to);
        else if(!po[to]) {puts("-1"); exit(0);}
    }
    po[u]=1;
}

int vis1[N],vis2[N];
char s[N]; int ans=0;
void dfs1(int u){
    vis1[u]=1;
    for(auto &to : v[u]) if(!vis1[to]) dfs1(to);
}
void dfs2(int u){
    vis2[u]=1;
    for(auto &to : G[u]) if(!vis2[to]) dfs2(to);
}
int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        v[x].push_back(y); G[y].push_back(x);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    for(int i=1;i<=n;i++){
        if(!vis1[i]&&!vis2[i]) ans++,s[i]='A';
        else s[i]='E';
        dfs1(i); dfs2(i);
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) printf("%c",s[i]);
    return 0;
}