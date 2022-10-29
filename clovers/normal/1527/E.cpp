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
const int N=36005;
const int M=105;
int n,k,pre[N],a[N],now[N];
struct Segment_Tree{
    int mi[N<<2],tag[N<<2];
    void pushup(int x){mi[x]=min(mi[x<<1],mi[x<<1|1]);}
    void build(int x,int l,int r){
        if(l==r){mi[x]=inf; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void pushdown(int x){
        if(tag[x]){
            tag[x<<1]+=tag[x]; tag[x<<1|1]+=tag[x];
            mi[x<<1]+=tag[x]; mi[x<<1|1]+=tag[x];
            tag[x]=0;
        }
    }
    void update(int x,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){mi[x]+=val; tag[x]+=val; return;}
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=L) update(x<<1,l,mid,L,R,val);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
        pushup(x);
    }
    void change(int x,int l,int r,int pos,int val){
        if(l==r){mi[x]=val; return;}
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=pos) change(x<<1,l,mid,pos,val);
        else change(x<<1|1,mid+1,r,pos,val);
        pushup(x);
    }
    int query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return mi[x];
        int mid=(l+r)>>1,ret=inf; pushdown(x);
        if(mid>=L) checkmin(ret,query(x<<1,l,mid,L,R));
        if(mid<R) checkmin(ret,query(x<<1|1,mid+1,r,L,R));
        return ret;
    }
}T[M];

int main()
{
    n=read(); k=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) pre[i]=now[a[i]],now[a[i]]=i;
    for(int i=0;i<=k;i++) T[i].build(1,0,n);
    T[0].change(1,0,n,0,0);
    for(int i=1;i<=n;i++){
        if(pre[i]){
            for(int j=0;j<=min(i,k);j++){
                T[j].update(1,0,n,0,pre[i]-1,i-pre[i]);
            }
        }
        for(int j=1;j<=min(i,k);j++){
            int val=T[j-1].query(1,0,n,0,i-1);
            T[j].change(1,0,n,i,val);
        }
    }
    // for(int i=0;i<=n;i++){
    //     outln(i);
    //     for(int j=0;j<=k;j++){cout<<(j)<<" "; cout<<(T[j].query(1,0,n,i,i))<<endl;}
    // }
    cout<<T[k].query(1,0,n,n,n)<<endl;
    return 0;
}