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
int n,a[N],val[N],m; vector<int> v[N];
multiset<int> st;
namespace DSU{
    int fa[N],sz[N];
    void init(){for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;}
    int getfather(int x){return x==fa[x] ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){
        x=getfather(x); y=getfather(y);
        if(x==y) return;
        st.erase(st.lower_bound(sz[x])); st.erase(st.lower_bound(sz[y]));
        st.insert(sz[x]+sz[y]); fa[x]=y; sz[y]+=sz[x];
    }
}

int mx=0,ans=0,vis[N];
int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),val[i]=a[i];
    DSU::init();
    sort(val+1,val+n+1); m=unique(val+1,val+n+1)-val-1;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(val+1,val+m+1,a[i])-val;
        v[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        for(auto &u : v[i]){
            vis[u]=1; st.insert(1);
            if(vis[u-1]) DSU::unite(u,u-1);
            if(vis[u+1]) DSU::unite(u,u+1);
        }
        if(st.empty()||(*st.begin()==(*(--st.end())))){
            if(mx<sz(st)) mx=sz(st),ans=val[i]+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}