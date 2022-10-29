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
const int M=1005;
#define int long long
int n,a[N],pos[N];

struct BIT{
    ll a[N];
    int lowbit(int x){return x&(-x);}
    void update(int x,int add){
        for(int i=x;i<=n;i+=lowbit(i)) a[i]+=add;
    }
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret;
    }
}tree1,tree2;

int find(int x){
    int l=1,r=n,mid,best;
    while(l<=r){
        mid=(l+r)>>1;
        if(tree1.query(mid)>x/2) r=mid-1,best=mid;
        else l=mid+1;
    }
    return best;
}

signed main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
    ll ans=0,inv=0,sum=0;
    for(int i=1;i<=n;i++){
        inv+=i-1-tree1.query(pos[i]);
        ans=inv; sum+=pos[i];
        tree1.update(pos[i],1);
        tree2.update(pos[i],pos[i]);
        int mid=find(i);
        ll left=tree1.query(mid),right=i-left;
        ll L=tree2.query(mid),R=sum-L;
        left--; L-=mid;
        ans+=R-mid*right+mid*left-L-(left+1)*left/2-(right+1)*right/2;
        printf("%lld ",ans);
    }
    cout<<endl;
    return 0;
}