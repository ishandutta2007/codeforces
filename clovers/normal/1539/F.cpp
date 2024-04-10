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
struct node{
    int sum,lmi,rmi,lmx,rmx;
};
node newnode(int val){
    node A;
    A.sum=val; A.lmi=A.rmi=min(A.sum,0);
    A.lmx=A.rmx=max(A.sum,0);
    return A;
}
node merge(node A,node B){
    node C;
    C.sum=A.sum+B.sum;
    C.lmx=max(A.lmx,A.sum+B.lmx); C.lmi=min(A.lmi,A.sum+B.lmi);
    C.rmx=max(B.rmx,B.sum+A.rmx); C.rmi=min(B.rmi,B.sum+A.rmi);
    return C;
}

struct Segment_Tree{
    node a[N<<2];
    void pushup(int x){a[x]=merge(a[x<<1],a[x<<1|1]);}
    void build(int x,int l,int r){
        if(l==r){a[x]=newnode(-1); return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void update(int x,int l,int r,int pos,int val){
        if(l==r){a[x]=newnode(val); return;}
        int mid=(l+r)>>1;
        if(mid>=pos) update(x<<1,l,mid,pos,val);
        else update(x<<1|1,mid+1,r,pos,val);
        pushup(x);
    }
    node query(int x,int l,int r,int L,int R){
        if(L>R) return newnode(0);
        if(L<=l&&r<=R) return a[x];
        int mid=(l+r)>>1; node ret=newnode(0);
        if(mid>=L) ret=merge(ret,query(x<<1,l,mid,L,R));
        if(mid<R) ret=merge(ret,query(x<<1|1,mid+1,r,L,R));
        return ret;
    }
}T;
int n,a[N]; vector<int> v[N];
int ans[N];
int calcr(int pos){
    node pre=T.query(1,1,n,1,pos),nxt=T.query(1,1,n,pos+1,n);
    int len=_abs(pre.rmi+nxt.lmi);
    return len-(len/2+1);
}
int calcl(int pos){    
    node pre=T.query(1,1,n,1,pos),nxt=T.query(1,1,n,pos+1,n);
    int len=pre.rmx+nxt.lmx;
    return len/2;
}

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read(),v[a[i]].push_back(i);
    T.build(1,1,n);
    for(int i=n;i>=1;i--){
        for(auto &u : v[i]) ans[u]=calcr(u);
        for(auto &u : v[i]) T.update(1,1,n,u,1);
        for(auto &u : v[i]) checkmax(ans[u],calcl(u));
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}