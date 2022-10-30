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
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=5005;
int n,S,T,nxt[N];
ll a[N],b[N],c[N],d[N],x[N];
void init(){
    scanf("%d%d%d",&n,&S,&T);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=x[i];
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]),b[i]-=x[i];
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]),c[i]+=x[i];
    for(int i=1;i<=n;i++) scanf("%lld",&d[i]),d[i]-=x[i];
}

ll calc(ll i,ll j){
    return i<j ? d[i]+a[j] : c[i]+b[j];
}

int main()
{
    init();
    ll ans=0; nxt[S]=T;
    ans=calc(S,T);
    for(int i=1;i<=n;i++){
        if(i==S||i==T) continue;
        ll tmp=INF; int id=S;
        for(int j=S;j!=T;j=nxt[j]){
            if(tmp>-calc(j,nxt[j])+calc(j,i)+calc(i,nxt[j])){
                tmp=-calc(j,nxt[j])+calc(j,i)+calc(i,nxt[j]);
                id=j;
            }
        }
        nxt[i]=nxt[id]; nxt[id]=i; ans+=tmp;
    }
    cout<<ans<<endl;
    return 0;
}