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
const int MOD=1e9+7;
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
const int N=55;
int dp[N][N][2],n=30,x,a[N];

int main()
{
    x=read();
    for(int i=29;i>=0;i--){
        a[i+1]=(x>>i&1);
    }
    reverse(a+1,a+n+1);
    int ans=0;
    //outln(a[30]);
    int flag=1;
    for(int i=0;i<=n;i++){
        if(a[i]) flag=0;
        dp[i][0][flag]=1;
        for(int j=0;j<=i;j++){
            for(int bl=0;bl<=1;bl++) if(dp[i][j][bl]){
                if(i==n) {Add(ans,dp[i][j][bl]); continue;}
                for(int p=0;p<=1;p++){
                    if(bl&&p>a[i+1]) continue;
                    if(p==1) Add(dp[i+1][j+1][bl&&p==a[i+1]],dp[i][j][bl]);
                    if(j) Add(dp[i+1][j][bl&&p==a[i+1]],mul(dp[i][j][bl],qpow(2,j-1)));
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}