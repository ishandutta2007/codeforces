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
int n,m=0,a[N],pos[N],nxt[N];
vector<pii> v[N];
ll ans[N],sum[N];
struct BIT2{
    ll a[N];
    int lowbit(int x){return x&(-x);}
    void update(int x,int val){for(int i=x;i<=m;i+=lowbit(i)) a[i]+=val;}
    ll query(int x){
        ll ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret;
    }
}T1,T2;
int main()
{
    n=read(); 
    for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i,sum[i]=sum[i-1]+a[i],checkmax(m,a[i]);
    
    for(int i=1;i<=n;i++){
        ans[i]+=T2.query(a[i])+1ll*(i-1)*a[i];
        for(int j=a[i];j<=m;j+=a[i]){
            T2.update(j,-a[i]);
            ans[i]-=(T1.query(min(m,j+a[i]-1))-T1.query(j-1))*j;
        }
        ans[i]+=sum[i-1];
        T1.update(a[i],1);
    }
    for(int i=2;i<=n;i++) ans[i]+=ans[i-1];
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]); puts("");
    return 0;
}