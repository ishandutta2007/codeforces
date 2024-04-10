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
const int MOD=1e9+7;
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
int n,q,dfn[N],cnt=0,dep[N],sz[N],fa[N],id[N];
vector<int> v[N];
void dfs(int u){
    dfn[u]=++cnt; sz[u]=1; id[cnt]=u;
    for(auto &to : v[u]){
        dep[to]=dep[u]+1;
        dfs(to); sz[u]+=sz[to];
    }
}
struct Segment_Tree{
    int tags[N<<2],tagk[N<<2],sum[N<<2];
    void pushdown(int x){
        if(tagk[x]){
            Add(tagk[x<<1],tagk[x]); Add(tagk[x<<1|1],tagk[x]);
            tagk[x]=0;
        }
        if(tags[x]){
            Add(tags[x<<1],tags[x]); Add(sum[x<<1],tags[x]);
            Add(tags[x<<1|1],tags[x]); Add(sum[x<<1|1],tags[x]);
            tags[x]=0;
        }
    }
    void update(int x,int l,int r,int L,int R,int val,int k){
        if(L<=l&&r<=R){Add(tagk[x],k); Add(tags[x],val); Add(sum[x],val); return;}
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=L) update(x<<1,l,mid,L,R,val,k);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val,k);
    }
    int query(int x,int l,int r,int pos){
        if(l==r) return sub(sum[x],mul(tagk[x],dep[id[pos]]));
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=pos) return query(x<<1,l,mid,pos);   
        else return query(x<<1|1,mid+1,r,pos);
    }
}tree;

int main()
{
    n=read();
    for(int i=2;i<=n;i++) fa[i]=read(),v[fa[i]].push_back(i);
    dfs(1);
    q=read();
    for(int i=1;i<=q;i++){
        int opt=read(),p=read();
        if(opt==1){
            int x=read(),k=read();
            tree.update(1,1,n,dfn[p],dfn[p]+sz[p]-1,add(x,mul(dep[p],k)),k);
        }
        else printf("%d\n",tree.query(1,1,n,dfn[p]));
    }
    return 0;
}