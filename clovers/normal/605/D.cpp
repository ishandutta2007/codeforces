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
int a[N],b[N],c[N],d[N],n;
vector<pii> v[N<<2];
int val[N<<2],m=0;
int findval(int x){return lower_bound(val+1,val+m+1,x)-val;}
int flag=0,dis[N],pre[N];
queue<int> q;

struct Segment_Tree{
    int mi[N<<4];
    void pushup(int x){mi[x]=min(mi[x<<1],mi[x<<1|1]);}
    void build(int x,int l,int r){
        mi[x]=inf;
        if(l==r){
            if(!v[l].empty()) mi[x]=v[l].back().first;
            return;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void find(int x,int l,int r,int L,int R,int D,int lim,int Pre){
        if(l==r){
            while(!v[l].empty()&&v[l].back().first<=lim){
                pii u=v[l].back(); v[l].pop_back();
                dis[u.second]=D; q.push(u.second); pre[u.second]=Pre;
            }
            mi[x]=inf;
            if(!v[l].empty()) mi[x]=v[l].back().first;
            return;
        }
        int mid=(l+r)>>1;
        if(L<=l&&r<=R){
            if(mi[x<<1]<=lim) find(x<<1,l,mid,L,R,D,lim,Pre);
            if(mi[x<<1|1]<=lim) find(x<<1|1,mid+1,r,L,R,D,lim,Pre);
            pushup(x); return;
        }
        if(mid>=L) find(x<<1,l,mid,L,R,D,lim,Pre);
        if(mid<R) find(x<<1|1,mid+1,r,L,R,D,lim,Pre);
        pushup(x);
    }
}tree;

void run(){
    tree.build(1,1,m);
    q.push(0);
    memset(dis,0x3f,sizeof(dis)); dis[0]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        tree.find(1,1,m,1,c[u],dis[u]+1,d[u],u);
    }
    if(dis[n]>inf){puts("-1"); return;}
    vector<int> ans; int x=n;
    while(x) ans.push_back(x),x=pre[x];
    printf("%d\n",sz(ans));
    while(!ans.empty()) printf("%d ",ans.back()),ans.pop_back();
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read(),b[i]=read(),c[i]=read(),d[i]=read();
        val[++m]=a[i]; val[++m]=b[i];
        val[++m]=c[i]; val[++m]=d[i];
        if(!a[i]&&!b[i]) flag=1;
    }
    if(!flag){puts("-1"); return 0;}
    sort(val+1,val+m+1); m=unique(val+1,val+m+1)-val-1;
    for(int i=0;i<=n;i++){
        a[i]=findval(a[i]); b[i]=findval(b[i]);
        c[i]=findval(c[i]); d[i]=findval(d[i]);
    }
    for(int i=1;i<=n;i++) v[a[i]].push_back(mk(b[i],i));
    for(int i=1;i<=m;i++){
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
    }
    run();
    return 0;
}