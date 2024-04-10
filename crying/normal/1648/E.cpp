#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,INF=2e9;
int T,n,m,a[MAXN],b[MAXN],c[MAXN],now;
int power[20],val[MAXN][20],fa[MAXN][20],depth[MAXN];
vector<array<int,2> >e[MAXN];
map<array<int,2>,int>qwq;
class DSU{public:
    int fa[MAXN],sz[MAXN];
    vector<int>val[MAXN];
    void reset(){rep(i,1,n)fa[i]=i,val[i].clear(),val[i].push_back(i),sz[i]=1;}
    int Find(int x){
        if(fa[x]==x)return x;
        return fa[x]=Find(fa[x]);
    }
    void Merge(int x,int y){
        if(sz[y]>sz[x])swap(x,y);
        for(auto u:val[y])val[x].push_back(u);
        val[y].clear();
        fa[y]=x;
    }
}d2;
class DSU2:public DSU{public:
    set<int>ver[MAXN];
    void reset(){rep(i,1,n)fa[i]=i,sz[i]=1,ver[i].clear(),ver[i].insert(i);}
    void Merge(int x,int y){
        if(sz[y]>sz[x])swap(x,y);
        //merge ver,instead of merge val 
        vector<int>tmp;tmp.clear();
        for(auto cy:ver[y]){
            int flag=0,fst=0;
            vector<int>del;del.clear();
            for(auto cx:ver[x]){
                int facx=d2.Find(cx),facy=d2.Find(cy);
                for(auto u:d2.val[facx])for(auto v:d2.val[facy])if(qwq.find({u,v})==qwq.end()){
                    if(flag)del.push_back(facx);
                    else fst=facx;
                    e[u].push_back({v,now});e[v].push_back({u,now});
                    flag++;
                    goto END;
                }
                END:;
            }
            if(flag>=2)for(auto num:del){d2.Merge(fst,num);ver[x].erase(num);}
            if(flag)d2.Merge(fst,d2.Find(cy));
            else tmp.push_back(cy);
        }
        for(auto u:tmp)ver[x].insert(u);
        sz[x]+=sz[y];
        fa[y]=x;
    }
}d1;
int arr[MAXN];
bool cmp(const int& x,const int& y){return c[x]<c[y];}
void dfs(int u){
    depth[u]=depth[fa[u][0]]+1;
    rep(i,1,19)fa[u][i]=fa[fa[u][i-1]][i-1];
    rep(i,1,19)val[u][i]=max(val[u][i-1],val[fa[u][i-1]][i-1]);
    for(auto p:e[u]){
        int v=p[0],w=p[1];
        if(v==fa[u][0])continue;
        fa[v][0]=u;val[v][0]=w;
        dfs(v);
    }
}
int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    int ret=0;
    per(j,19,0)if(depth[x]-power[j]>=depth[y]){
        ret=max(ret,val[x][j]);
        x=fa[x][j];
    }
    if(x==y)return ret;
    per(j,19,0)if(fa[x][j]!=fa[y][j]){
        ret=max(ret,val[x][j]);
        ret=max(ret,val[y][j]);
        x=fa[x][j],y=fa[y][j];
    }
    ret=max(ret,val[x][0]);
    ret=max(ret,val[y][0]);
    return ret;
}
void solve(){
    cin>>n>>m;qwq.clear();
    rep(i,1,m)cin>>a[i]>>b[i]>>c[i],arr[i]=i,qwq[{a[i],b[i]}]=qwq[{b[i],a[i]}]=1;
    sort(arr+1,arr+1+m,cmp);
    d1.reset();d2.reset();
    rep(i,1,n)e[i].clear();
    rep(j,1,m){
        int i=arr[j];
        int u=a[i],v=b[i];now=c[i];
        int p=d1.Find(u),q=d1.Find(v);
        if(p==q)continue;
        d1.Merge(p,q);
    }
    rep(i,0,n){depth[i]=0;rep(j,0,19)fa[i][j]=0,val[i][j]=0;}
    dfs(1);
    rep(i,1,m){
        int ans=lca(a[i],b[i]);
        cout<<ans<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    rep(i,0,19)power[i]=1<<i;
    cin>>T;
    while(T--)solve();
    return 0;
}