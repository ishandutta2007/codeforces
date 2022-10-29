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
const int N=1000005;
int a[N],b[N],val[N<<1],top=0,n,m;
int findval(int x){return lower_bound(val+1,val+top+1,x)-val;}
struct Segment_Tree{
    int mi[N<<2],tag[N<<2];
    void pushup(int x){mi[x]=min(mi[x<<1],mi[x<<1|1]);}
    void pushdown(int x){
        if(tag[x]){
            mi[x<<1]+=tag[x]; mi[x<<1|1]+=tag[x];
            tag[x<<1]+=tag[x]; tag[x<<1|1]+=tag[x];
            tag[x]=0;
        }
    }
    void build(int x,int l,int r){
        tag[x]=0;
        if(l==r){mi[x]=l; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void update(int x,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){tag[x]+=val; mi[x]+=val; return;}
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=L) update(x<<1,l,mid,L,R,val);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
        pushup(x);
    }
}T;
ll sum=0;
struct BIT{
    int a[N<<1];
    void init(){for(int i=1;i<=top;i++) a[i]=0;}
    int lowbit(int x){return x&(-x);}
    void update(int x){for(int i=x;i<=top;i+=lowbit(i)) a[i]++;}
    int query(int x){int ret=0; for(int i=x;i;i-=lowbit(i)) ret+=a[i]; return ret;}
}T2;
pii p[N];

void solve(){
    top=0; sum=0;
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read(),val[++top]=a[i];
    for(int i=1;i<=m;i++) b[i]=read(),val[++top]=b[i]; 
    sort(b+1,b+m+1);
    sort(val+1,val+top+1); top=unique(val+1,val+top+1)-val-1;
    for(int i=1;i<=n;i++) a[i]=findval(a[i]);
    for(int i=1;i<=m;i++) b[i]=findval(b[i]);
    T2.init();
    for(int i=n;i>=1;i--){
        sum+=T2.query(a[i]-1),T2.update(a[i]);
    }
    // outln(sum);
    for(int i=1;i<=n;i++) p[i]=mk(a[i],i);
    sort(p+1,p+n+1);
    T.build(1,0,n);
    int i1=1,i2=1;
    for(int i=1;i<=m;i++){
        while(i1<=n&&p[i1].first<=b[i]) T.update(1,0,n,p[i1].second,n,-1),i1++;
        while(i2<=n&&p[i2].first<b[i]) T.update(1,0,n,0,p[i2].second-1,1),i2++;
        sum+=T.mi[1];
    }
    printf("%lld\n",sum);
}

int main()
{
    int T=read();
    while(T--){solve();}
    return 0;
}