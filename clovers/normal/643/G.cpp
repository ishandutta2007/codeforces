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
const int N=150005;
int n,len,a[N];
struct node{pii a[6];};
node operator + (node A,node B){
    node C;
    pii t[11]; int top=0;
    for(int i=1;i<=len;i++){
        int flag=0;
        for(int j=1;j<=top;j++) if(t[j].second==A.a[i].second) t[j].first+=A.a[i].first,flag=1;
        if(!flag) t[++top]=A.a[i];
        flag=0;
        for(int j=1;j<=top;j++) if(t[j].second==B.a[i].second) t[j].first+=B.a[i].first,flag=1;
        if(!flag) t[++top]=B.a[i];
    }
    sort(t+1,t+top+1); reverse(t+1,t+top+1);
    for(int i=len+1;i<=top;i++){
        for(int j=len;j>=1;j--){
            if(t[j].first<t[i].first){
                for(int k=j-1;k>=1;k--) t[k].first-=t[j].first;
                t[j]=mk(t[i].first-t[j].first,t[i].second);
                break;
            }
            else t[j].first-=t[i].first;
        }
    }
    for(int i=1;i<=len;i++) C.a[i]=t[i];
    return C;
}

struct Segment_Tree{
    node sum[N<<2]; int tag[N<<2];
    void pushup(int x){sum[x]=sum[x<<1]+sum[x<<1|1];}
    void build(int x,int l,int r){
        if(l==r){
            for(int i=1;i<=len;i++) sum[x].a[i]=mk(0,0);
            sum[x].a[1]=mk(1,a[l]);
            return;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void pushtag(int x,int l,int r,int val){
        for(int i=1;i<=len;i++) sum[x].a[i]=mk(0,0);
        tag[x]=val;
        sum[x].a[1]=mk(r-l+1,val);
    }
    void pushdown(int x,int l,int mid,int r){
        if(tag[x]){
            pushtag(x<<1,l,mid,tag[x]); pushtag(x<<1|1,mid+1,r,tag[x]);
            tag[x]=0;
        }
    }
    void update(int x,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            pushtag(x,l,r,val);
            return;
        }
        int mid=(l+r)>>1; pushdown(x,l,mid,r);
        if(mid>=L) update(x<<1,l,mid,L,R,val);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
        pushup(x);
    }
    node query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[x];
        node ret; for(int i=1;i<=len;i++) ret.a[i]=mk(0,0);
        int mid=(l+r)>>1; pushdown(x,l,mid,r);
        if(mid>=L) ret=ret+query(x<<1,l,mid,L,R);
        if(mid<R) ret=ret+query(x<<1|1,mid+1,r,L,R);
        return ret;
    }
}tree;

int main()
{
    n=read(); int m=read(),p=read(); len=100/p;
    for(int i=1;i<=n;i++) a[i]=read();
    tree.build(1,1,n);
    while(m--){
        int typ=read();
        if(typ==1){
            int l=read(),r=read(),id=read();
            tree.update(1,1,n,l,r,id);
        }
        else{
            int l=read(),r=read();
            node ret=tree.query(1,1,n,l,r);
            printf("%d ",len);
            for(int i=1;i<=len;i++) printf("%d ",ret.a[i].second);
            puts("");
        }
    }
    return 0;
}