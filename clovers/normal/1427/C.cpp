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
const int N=100005;
int dp[N],n;
struct node{
    int x,y,t;
}a[N];
int t[N*10],r;

int calc(int i,int j){
    return _abs(a[i].x-a[j].x)+_abs(a[i].y-a[j].y);
}

int main()
{
    r=read(); n=read();
    for(int i=1;i<=n;i++){
        a[i].t=read(); a[i].x=read(); a[i].y=read();
        t[a[i].t]=i;
    }
    a[0].t=0; a[0].x=1; a[0].y=1;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    int mx=-1,pre=-1; 
    for(int i=1;i<=n;i++){
        int j=i-1;
        while(a[i].t-2*r<a[j].t&&j>=0){
            if(a[j].t+calc(i,j)<=a[i].t&&dp[j]!=-1){
                checkmax(dp[i],dp[j]+1);
            }
            j--;
        }
        while(pre<j) pre++,checkmax(mx,dp[pre]);
        if(mx!=-1) checkmax(dp[i],mx+1);
    }
    int ans=0;
    for(int i=0;i<=n;i++) checkmax(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}