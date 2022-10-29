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
#define int long long
const int N=100005;
int n,a[N],sum[2][N];

signed main()
{
    n=read()-1; for(int i=1;i<=n+1;i++) a[i]=read();
    for(int i=1;i<=n;i++) a[i]=_abs(a[i]-a[i+1]);
    for(int i=1;i<=n;i++){
        int cur=(i&1);
        sum[cur][i]=sum[cur][i-1]+a[i];
        sum[cur^1][i]=sum[cur^1][i-1]-a[i];
    }
    int mx1=-INF,mx2=-INF,ans=0;
    for(int i=n-1;i>=0;i--){
        if(i&1) checkmax(mx2,sum[0][i+1]),checkmax(ans,mx2-sum[0][i]);
        else checkmax(mx1,sum[1][i+1]),checkmax(ans,mx1-sum[1][i]);
        // out(i); out(mx1); outln(mx2);
    }
    cout<<ans<<endl;
    return 0;
}