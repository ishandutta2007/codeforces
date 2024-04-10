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
const int N=300005;
const int M=1000000;
int n,m,a[N],b[N];
struct Segment_Tree{
    int mx[M<<2],tag[M<<2];
    void pushup(int x){mx[x]=max(mx[x<<1],mx[x<<1|1]);}
    void pushdown(int x){
        if(tag[x]){
            tag[x<<1]+=tag[x]; tag[x<<1|1]+=tag[x];
            mx[x<<1]+=tag[x]; mx[x<<1|1]+=tag[x];
            tag[x]=0;
        }
    }
    void update(int x,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){mx[x]+=val; tag[x]+=val; return;}
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=L) update(x<<1,l,mid,L,R,val);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
        pushup(x);
    }
    int query(int x,int l,int r){
        if(mx[x]<=0) return -1;
        if(l==r) return l;
        int mid=(l+r)>>1; pushdown(x);
        if(mx[x<<1|1]>0) return query(x<<1|1,mid+1,r);
        else return query(x<<1,l,mid); 
    }
}T;

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        T.update(1,1,M,1,a[i],1);
    }
    for(int i=1;i<=m;i++){
        b[i]=read();
        T.update(1,1,M,1,b[i],-1);
    }
    int q=read();
    while(q--){
        int opt=read(),x=read(),val=read();
        if(opt==1){
            T.update(1,1,M,1,a[x],-1);
            a[x]=val;
            T.update(1,1,M,1,a[x],1);
        }
        else{
            T.update(1,1,M,1,b[x],1);
            b[x]=val;
            T.update(1,1,M,1,b[x],-1);
        }
        printf("%d\n",T.query(1,1,M));
    }
    return 0;
}