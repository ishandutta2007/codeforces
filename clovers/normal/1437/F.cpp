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
const int N=5005;
int n,a[N],dp[N];
int fac[N],ifac[N],lim[N];
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    fac[0]=1; for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    ifac[n]=qpow(fac[n],MOD-2); 
    for(int i=n-1;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(a[j]*2<=a[i]){lim[i]=j; break;}
        }
    }
}

void solve(){
    dp[0]=1;
    if(a[n]<a[n-1]*2){
        puts("0");
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=lim[i];j>=0;j--){
            int delta=lim[i]-lim[j]-1,rest=n-lim[j]-2;
            if(j==0) delta++,rest++;
            dp[i]=add(dp[i],mul(dp[j],mul(fac[rest],ifac[rest-delta])));
        }
    }
    cout<<dp[n]<<endl;
}

int main()
{
    init(); solve();
    return 0;
}