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
const int N=300005;
int n,p[N],q[N],pos[N];
struct node{
    int sum=0,mx=0,mi=0;
}a[N<<2];
node merge(node A,node B){
    node C;
    C.sum=A.sum+B.sum;
    C.mx=max(B.mx,B.sum+A.mx);
    C.mi=min(A.mi,A.sum+B.mi);
    return C;
}
struct Segment_Tree{
    void pushup(int x){a[x]=merge(a[x<<1],a[x<<1|1]);}
    void update(int x,int l,int r,int pos,int val){
        if(l==r){
            a[x].sum+=val; a[x].mx=max(0,a[x].sum); a[x].mi=min(0,a[x].sum);
            return;
        }
        int mid=(l+r)>>1;
        if(mid>=pos) update(x<<1,l,mid,pos,val);
        else update(x<<1|1,mid+1,r,pos,val);
        pushup(x);
    }
    node query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return a[x];
        int mid=(l+r)>>1;
        node ret=node{0,0,0};
        if(L>R) return ret;
        if(mid>=L) ret=merge(ret,query(x<<1,l,mid,L,R));
        if(mid<R) ret=merge(ret,query(x<<1|1,mid+1,r,L,R));
        return ret;
    }
}T;

bool check(int pos){
    node pre=T.query(1,1,n,1,pos);
    node nxt=T.query(1,1,n,pos+1,n);
    return pre.mx+nxt.mi>0; 
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) p[i]=read(),pos[p[i]]=i;
    for(int i=1;i<=n;i++) q[i]=read();
    printf("%d ",n);
    T.update(1,1,n,pos[n],1);
    for(int i=1,j=n;i<n;i++){
        T.update(1,1,n,q[i],-1);
        while(!check(pos[j])) j--,T.update(1,1,n,pos[j],1);
        printf("%d ",j);
    }
    return 0;
}