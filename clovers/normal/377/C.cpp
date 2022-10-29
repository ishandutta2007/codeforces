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
const int N=21;
int n,m,a[101],dp[1<<N];
int num[N]; char opt[N][2];

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    m=read();
    for(int i=1;i<=m;i++) scanf("%s%d",opt[i],&num[i]);
    sort(a+1,a+n+1); reverse(a+1,a+n+1);
    checkmin(n,m);
    int full=(1<<n)-1;
    for(int S=0;S<full;S++){
        int cnt=0;
        for(int i=0;i<n;i++) if(S>>i&1) cnt++; cnt++;
        if(num[cnt]==1) dp[S]=-inf;
        else dp[S]=inf;
    }
    for(int i=n;i>=1;i--){
        for(int S=1;S<=full;S++){
            int cnt=0;
            for(int j=0;j<n;j++) if(S>>j&1) cnt++;
            if(cnt!=i) continue;
            for(int j=0;j<n;j++) if(S>>j&1){
                if(num[i]==1){
                    if(opt[i][0]=='p') checkmax(dp[S^(1<<j)],dp[S]+a[j+1]);
                    else checkmax(dp[S^(1<<j)],dp[S]);
                }
                else{
                    if(opt[i][0]=='p') checkmin(dp[S^(1<<j)],dp[S]-a[j+1]);
                    else checkmin(dp[S^(1<<j)],dp[S]);
                }
            }
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}