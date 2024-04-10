#include<bits/stdc++.h>
#define PB(x) push_back(x)
using namespace std;
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
vector<int> E[maxn],ET[maxn];
int n,m,q;
int N;
int a[maxn],mapid[maxn],mapCnt;
bool inCircle[maxn];int bcc_no[maxn];
map<int,int> cnt[maxn];
int dfn[maxn],low[maxn],dfs_clock,fa[maxn];
int sz[maxn*2],wson[maxn*2],top[maxn*2],dep[maxn*2],pos[maxn*2];
char s[5];
inline int readInt(){
    char ch = getchar();
    while (ch<'0'||ch>'9')ch = getchar();
    int ret =0;
    while (ch>='0'&&ch<='9')ret = ret*10+ch-'0',ch = getchar();
    return ret;
}
inline char readChar(){
    char ch = getchar();
    while (ch<'A'||ch>'Z')ch = getchar();
    return ch;
}
pair<int,int> stk[maxn*2];int topp;
struct Seg_Tree{
    int val[maxn*8],cnt=0;
    inline void up(int x){
        val[x] = min(val[x<<1],val[x<<1|1]);
    }
    void modify(int x,int l,int r,int Index,int Val){
        if (l==r){
            val[x] =Val;
            return;
        }
        int mid = l+r >>1;
        if (Index<=mid)modify(x<<1,l,mid,Index,Val);
        else modify(x<<1|1,mid+1,r,Index,Val);
        up(x);
    }
    int query(int x,int l,int r,int L,int R){
        if (l>R||r<L)return INF;
        if (L<=l&&r<=R)return val[x];
        int mid = l+r >>1;
        return min(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
    }
}tree;
void input(){
    n = readInt();m = readInt();q = readInt();
   // scanf("%d%d%d",&n,&m,&q);
    N =n;
    for (int i=1;i<=n;i++){
      //  scanf("%d",a+i);
              a[i] = readInt();
    }
    for (int i=0;i<m;i++){
        int u=readInt(),v=readInt();
       // scanf("%d%d",&u,&v);
        E[u].PB(v);E[v].PB(u);
    }
}
void tarjan(int u,int fa,pair<int,int>Eid){
    dfn[u] = low[u] = ++dfs_clock;
    for (int i=0;i<E[u].size();i++){
        int v = E[u][i];
        if (v==fa)continue;
        if (!dfn[v]){
            stk[topp++] = {u,v};
            tarjan(v,u,{u,v});
            low[u] = min(low[u],low[v]);
            if (low[v]==dfn[u]){
                n++;
                mapid[n-N] = ++mapCnt;
                ET[u].PB(n);
                while (true){
                    pair<int,int> tt = stk[--topp];
                    if (bcc_no[tt.second]!=n){
                        bcc_no[tt.second] =n;
                        if (tt.second!=u)
                            ET[n].PB(tt.second),cnt[mapid[n-N]][a[tt.second]]++;

                    }
                    if (tt==(pair<int,int>){u,v})break;
                }
            }
        }else if (dfn[v]<dfn[u]){
            stk[topp++] = {u,v};
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (stk[topp-1]==Eid)topp--,ET[Eid.first].PB(Eid.second);
}
void dfs1(int u){
    sz[u]=1;
    dep[u] =dep[fa[u]]+1;
    for (int i=0;i<ET[u].size();i++){
        int v = ET[u][i];
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if (sz[v]>sz[wson[u]])wson[u] =v;
    }
}
void dfs2(int u,int chain){
    pos[u] = ++tree.cnt;
    top[u] = chain;
    if (fa[u]>N){
        a[fa[u]] = min(a[fa[u]],a[u]);
    }
    if (wson[u])dfs2(wson[u],chain);
    for (int i=0;i<ET[u].size();i++){
        int v = ET[u][i];
        if (v==fa[u]||v==wson[u])continue;
        dfs2(v,v);
    }
    tree.modify(1,1,n,pos[u],a[u]);
}
void build(){
    tarjan(1,0,{0,0});
    dfs1(1);
    dfs2(1,1);
}
int query(int x,int y){
    if (x==y)return a[x];
    int ret = INF;
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]]){
            swap(x,y);
        }
        ret = min(ret,tree.query(1,1,n,pos[top[x]],pos[x]));
        x = fa[top[x]];
    }
    if(dep[x]<dep[y])swap(x,y);
    ret = min(ret,tree.query(1,1,n,pos[y],pos[x]));
    if (y>N){
        ret = min(ret,a[fa[y]]);
    }
    return ret;
}
void solve(){
    while (q--){
        int x,y;
        s[0] = readChar();x = readInt();y = readInt();
       // scanf("%s%d%d",s,&x,&y);
        if (s[0]=='A'){
            printf("%d\n",query(x,y));
        }else{
            tree.modify(1,1,n,pos[x],y);
            if (fa[x]>N){
                cnt[mapid[fa[x]-N]][a[x]]--;
                if (cnt[mapid[fa[x]-N]][a[x]]==0){
                    cnt[mapid[fa[x]-N]].erase(a[x]);
                }
                cnt[mapid[fa[x]-N]][y]++;
                int temp=(*cnt[mapid[fa[x]-N]].begin()).first;
                if (temp!=a[fa[x]]){
                    a[fa[x]]=temp;
                    tree.modify(1,1,n,pos[fa[x]],temp);
                }
            }
            a[x]=y;
        }
    }
}
int main(){
    memset(a,INF,sizeof a);
    input();
    build();
    solve();
    return 0;
}