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
int n,m;
struct Segment_Tree{
    ll sum[N<<2],tag[N<<2],col[N<<2];
    void pushdown(int x,int l,int mid,int r){
        if(tag[x]){
            tag[x<<1]+=tag[x]; sum[x<<1]+=1ll*tag[x]*(mid-l+1);
            tag[x<<1|1]+=tag[x]; sum[x<<1|1]+=1ll*tag[x]*(r-mid);
            tag[x]=0;
        }
        if(col[x]!=-1) col[x<<1]=col[x],col[x<<1|1]=col[x];
    }
    void pushup(int x){sum[x]=sum[x<<1]+sum[x<<1|1];}
    void update(int x,int l,int r,int L,int R,int val){
        int mid=(l+r)>>1; pushdown(x,l,mid,r);
        if(L<=l&&r<=R){
            if(col[x]!=-1){
                sum[x]+=1ll*(r-l+1)*_abs(val-col[x]);
                tag[x]+=_abs(val-col[x]); col[x]=val;
            }
            else{
                update(x<<1,l,mid,L,R,val); 
                update(x<<1|1,mid+1,r,L,R,val);
                pushup(x);
                col[x]=val;
            }
            return;
        }
        col[x]=-1;
        if(mid>=L) update(x<<1,l,mid,L,R,val);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
        pushup(x);   
    }
    ll query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[x];
        ll ret=0; int mid=(l+r)>>1;
        pushdown(x,l,mid,r);
        if(mid>=L) ret+=query(x<<1,l,mid,L,R);
        if(mid<R) ret+=query(x<<1|1,mid+1,r,L,R);
        return ret;
    }
    void build(int x,int l,int r){
        if(l==r){col[x]=l; sum[x]=0; tag[x]=0; return;}
        int mid=(l+r)>>1; col[x]=-1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
}tree;

int main()
{
    n=read(); m=read();
    tree.build(1,1,n);
    while(m--){
        int opt=read(),l=read(),r=read();
        if(opt==1){
            int val=read();
            tree.update(1,1,n,l,r,val);
        }
        else printf("%lld\n",tree.query(1,1,n,l,r));
    }
    return 0;
}