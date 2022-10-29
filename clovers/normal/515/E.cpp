/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define int long long
typedef pair<int,int> pii;
const int N=200005;
int n,m,d[N],h[N];
struct node{pii A,B;};
struct Segment_Tree{
    node a[N<<2];
    int mx[N<<2];
    pii merge(pii A,pii B){
        int a[4]; int top=0;
        a[0]=A.first; a[1]=A.second; a[2]=B.first; a[3]=B.second;
        sort(a,a+4);
        return mk(a[3],a[2]);
    }
    node merge2(node A,node B){
        node C;
        C.A=merge(A.A,B.A); C.B=merge(A.B,B.B);        
        return C;
    }
    void pushup(int x){
        a[x]=merge2(a[x<<1],a[x<<1|1]);
        mx[x]=max(mx[x<<1],mx[x<<1|1]);
    }
    node query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R){return a[x];}
        int mid=(l+r)>>1;
        node ret; ret.A=mk(-INF,-INF); ret.B=mk(-INF,-INF);
        if(mid>=L) ret=merge2(ret,query(x<<1,l,mid,L,R));
        if(mid<R) ret=merge2(ret,query(x<<1|1,mid+1,r,L,R));
        return ret;
    }
    int query2(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R){return mx[x];}
        int mid=(l+r)>>1;
        int ret=-INF;
        if(mid>=L) checkmax(ret,query2(x<<1,l,mid,L,R));
        if(mid<R) checkmax(ret,query2(x<<1|1,mid+1,r,L,R));
        return ret;
    }
    void build(int x,int l,int r){
        if(l==r){
            a[x].A=mk(2*h[l]-d[l],-INF);
            a[x].B=mk(2*h[l]+d[l],-INF);
            mx[x]=4*h[l];
            return;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
}tree;

signed main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) d[i]=read(),d[i+n]=d[i];
    for(int i=1;i<=n;i++) h[i]=read(),h[i+n]=h[i];
    n<<=1;
    for(int i=n;i>=1;i--) d[i]=d[i-1];
    for(int i=1;i<=n;i++) d[i]+=d[i-1];
    tree.build(1,1,n);
    //for(int i=1;i<=n;i++) cout<<2*h[i]-d[i]<<" "; cout<<endl;
    //for(int i=1;i<=n;i++) cout<<2*h[i]+d[i]<<" "; cout<<endl;
    while(m--){
        int l=read(),r=read(),L,R;
        if(l<=r) L=r+1,R=n/2+l-1;
        else R=l-1,L=r+1;
        node ret=tree.query(1,1,n,L,R);
        int ret2=tree.query2(1,1,n,L,R);
        int ans;
        if(ret.A.first+ret.B.first==ret2){
            ans=max(ret.A.second+ret.B.first,
                    ret.A.first+ret.B.second);
        }
        else ans=ret.A.first+ret.B.first;
        printf("%lld\n",ans);
    }
    return 0;
}