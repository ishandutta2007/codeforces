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
const int N=5005;
#define int long long
int _abs(int x){return x<0 ? -x : x;}
int t[N],a[N];
int n,mi[N]; 
bool dp[N][N]; 
bool check(int x,int y){
    return t[y]-t[x]>=_abs(a[x]-a[y]);
}

signed main()
{
    n=read();
    for(int i=1;i<=n;i++) t[i]=read(),a[i]=read();
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) mi[i]=INF;
    t[0]=0; a[0]=0;
    mi[0]=0;
    for(int i=0;i<n;i++){
        if(mi[i]>t[i]) continue;
        //the clone is in the ith position-mintime(mi) 
        //1.go to the i+1th and put the clone at i+1th position
        checkmin(mi[i+1],max(mi[i]+_abs(a[i]-a[i+1]),t[i]));
        //2.go to another position-j,put the clone,and go back to the i+1th position
        //remember to wait for the ith clone to be used
        for(int j=i+2;j<=n;j++){
            int go=max(t[i],mi[i]+_abs(a[i]-a[j]));
            int back=_abs(a[j]-a[i+1]);
            if(go+back<=t[i+1]) dp[i+1][j]=1;
        }

        //the clone is not in the ith position
        //1.the clone is not used for the i+1th
        for(int j=i+2;j<=n;j++) if(check(i,i+1)) dp[i+1][j]|=dp[i][j];
        //2.the clone is for the i+1th
        //2(1):directly goto the i+2th, update the minitime of i+2th(wait for the i+1th)
        if(dp[i][i+1]) checkmin(mi[i+2],max(t[i+1],t[i]+_abs(a[i]-a[i+2])));
        //2(2):go to another position j,and go back to the i+2th
        if(dp[i][i+1]){
            for(int j=i+3;j<=n;j++){
                int go=max(t[i+1],t[i]+_abs(a[i]-a[j]));
                int back=_abs(a[j]-a[i+2]);
                if(go+back<=t[i+2]) dp[i+2][j]=1;
            }
        }
    }
    if(mi[n]<=t[n]||dp[n-1][n]) puts("YES");
    else puts("NO");
    return 0;
}