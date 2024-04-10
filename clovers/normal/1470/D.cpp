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
int T,n,m,vis[N],col[N];
vector<int> v[N];
void dfs(int u,int bl){
    vis[u]=1; col[u]=bl;
    if(bl){
        vector<int> tmp; tmp.clear();
        for(auto &to : v[u]) if(!vis[to]) tmp.push_back(to);
        for(auto &to : v[u]) vis[to]=1;
        for(auto &to : v[u]) dfs(to,0);
    }
    else for(auto &to : v[u]) if(!vis[to]){
        dfs(to,1);
    }
}

int main()
{
    T=read();
    while(T--){
        n=read(); m=read();
        for(int i=1;i<=m;i++){
            int x=read(),y=read();
            v[x].push_back(y); v[y].push_back(x);
        }
        for(int i=1;i<=n;i++) vis[i]=0,col[i]=0;
        dfs(1,1);
        int flag=1;
        for(int i=1;i<=n;i++) flag&=vis[i];
        if(!flag){
            puts("NO");
            for(int i=1;i<=n;i++) v[i].clear();
            continue;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++) if(col[i]) ans.push_back(i);
        puts("YES");
        printf("%d\n",sz(ans));
        for(auto &u : ans) printf("%d ",u); puts("");
        for(int i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}