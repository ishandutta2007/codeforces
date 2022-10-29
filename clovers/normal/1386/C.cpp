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
const int N=200005;
int lim[N],n,m,q;
struct Edge{int x,y;}E[N];
int top=0,flag=0; pii stk[N<<2];
struct DSU{
    int fa[N<<1],sz[N<<1];
    void init(){for(int i=1;i<=n+n;i++) fa[i]=i,sz[i]=1;}
    int getfather(int x){return fa[x]==x ? x : getfather(fa[x]);}
    bool same(int x,int y){return getfather(x)==getfather(y);}
    void Combine(int x,int y){
        x=getfather(x); y=getfather(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        fa[y]=x; sz[x]+=sz[y]; stk[++top]=mk(x,y);
        if(y<=n) flag+=(getfather(y)==getfather(y+n));
        if(x<=n) flag+=(getfather(x)==getfather(x+n));
    }
    void unite(int x,int y){Combine(x,y+n); Combine(x+n,y);}
    void back(int num){
        while(top>num){
            int x=stk[top].first,y=stk[top].second;
            if(y<=n) flag-=(getfather(y)==getfather(y+n));
            if(x<=n) flag-=(getfather(x)==getfather(x+n));
            fa[y]=y; sz[x]-=sz[y]; top--;
        }
    }
}T;

void solve(int l,int r,int L,int R){
    if(L>R||l>r) return;
    int mid=(l+r)>>1;
    int now=top;
    for(int i=mid+1;i<=r;i++) T.unite(E[i].x,E[i].y);
    int pos=L-(flag!=0);
    int now2=top;
    if(!flag) for(int p=L;p<=min(mid,R);p++){
        lim[p]=mid;
        T.unite(E[p].x,E[p].y);
        if(flag||p==min(mid,R)) break;
        else pos++;
    }
    T.back(now2);
    if(l==r) {T.back(now); return;}
    solve(l,mid,L,pos);
    T.back(now);
    for(int i=L;i<=pos;i++) T.unite(E[i].x,E[i].y);
    solve(mid+1,r,pos+1,R);
}

int main()
{
    memset(lim,0x3f,sizeof(lim));
    n=read(); m=read(); q=read();
    T.init();
    for(int i=1;i<=m;i++) E[i].x=read(),E[i].y=read();
    solve(1,m,1,m);
    // for(int i=1;i<=m;i++) cout<<lim[i]<<" "; cout<<endl;
    while(q--){
        int l=read(),r=read();
        if(r>=lim[l]) puts("NO");
        else puts("YES");
    }
    return 0;
}