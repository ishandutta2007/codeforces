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
int T,n; vector<int> v[N];
int top[N],deg[N],bot[N],fa[N],bel[N],tot=0,vis[N];
vector<pii> del;
void dfs2(int u,int f,int col,int nowcol){
    bel[u]=nowcol;
    for(auto &to : v[u]) if(to!=f&&bel[to]==col){
        dfs2(to,u,col,nowcol);
    }
}
void dfs(int u,int f){
    for(auto &to : v[u]) if(to!=f){
        bel[to]=bel[u];
        dfs(to,u);
    }
    if(deg[u]>2&&f!=-1){
        del.push_back(mk(u,f)),deg[u]--,deg[f]--;
        tot++; dfs2(u,f,bel[u],tot);        
    }
    for(auto &to : v[u]) if(bel[to]==bel[u]){
        if(deg[u]<=2) break;
        tot++; del.push_back(mk(to,u));
        deg[to]--; deg[u]--;
        dfs2(to,u,bel[u],tot);
    }
}
void run(int x,int f){
    int flag=1;
    for(auto &to : v[x]) if(bel[to]==bel[x]&&to!=f) flag=0,run(to,x);
    if(flag) bot[bel[x]]=x;
}

int main()
{
    T=read();
    while(T--){
        n=read(); del.clear(); tot=1;
        for(int i=1;i<=n;i++) top[i]=0,bel[i]=0,deg[i]=0,vis[i]=0,v[i].clear();
        for(int i=1;i<n;i++){
            int x=read(),y=read();
            v[x].push_back(y); v[y].push_back(x);
            deg[x]++; deg[y]++;
        }
        bel[1]=1; dfs(1,-1);
        // for(auto &u : del) cout<<u.first<<" "<<u.second<<endl;
        // for(int i=1;i<=n;i++) out(i),out(bel[i]),outln(deg[i]);
        for(int i=1;i<=n;i++) if(deg[i]<=1&&!top[bel[i]]) top[bel[i]]=i,run(i,-1);
        // for(int i=1;i<=3;i++) out(i),out(top[i]),outln(bot[i]);
        printf("%d\n",sz(del));
        for(int i=0;i<sz(del);i++){
            printf("%d %d %d %d\n",del[i].first,del[i].second,
                                top[i+1],bot[i+2]);
        }
    }
    return 0;
}