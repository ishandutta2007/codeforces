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
const int N=2005;
int n,k,a[N],l[N],r[N],head[N],able[N][N];
ll dp[N],limit[N]; 

int main()
{
    n=read(); k=read();
    ll S=0;
    for(int i=1;i<=n;i++) l[i]=read(),r[i]=read(),a[i]=read(),S+=a[i];
    for(int i=1,j=1;i<=n;i=j+1){
        head[i]=1;
        j=i; ll sum=a[i],L=l[i],R=r[i];
        int len=R-L+1;
        checkmax(limit[i],sum-1ll*(len-1)*k);
        if((sum+k-1)/k>len){puts("-1"); return 0;}
        while((sum+k-1)/k>=len&&j<=n&&l[j+1]==r[j]){
            j++;
            if(j<=n) sum+=a[j], R=r[j];
            len=R-L+1; 
            checkmax(limit[i],sum-1ll*(len-1)*k);
            if((sum+k-1)/k>len){puts("-1"); return 0;}
        }
        a[i]=sum; r[i]=R;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(head[i]){
            a[++cnt]=a[i], r[cnt]=r[i], l[cnt]=l[i], limit[cnt]=limit[i];
        }
    }
    n=cnt;
    // for(int i=1;i<=n;i++){
    //     out(i); out(a[i]); out(l[i]); out(r[i]); outln(limit[i]);
    // }
    memset(dp,0x3f,sizeof(dp));
    dp[1]=0;
    for(int i=1;i<=n;i++){
        //out(i); outln(dp[i]);
        ll sum=a[i],rest=k-sum%k;
        if(i+1<=n) checkmin(dp[i+1],dp[i]+rest);
        else checkmin(dp[i+1],dp[i]);
        for(int j=i+1;j<=n;j++){
            if(rest<limit[j]) break;
            sum+=a[j];
            rest=k-sum%k;
            if(j+1<=n) checkmin(dp[j+1],dp[i]+rest);
            else checkmin(dp[j+1],dp[i]);
        }
    }
    cout<<dp[n+1]+S<<endl;
    return 0;
}