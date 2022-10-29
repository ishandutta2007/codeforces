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
const int N=500005;
const int M=1005;
int n,a[N],s1,s2;
int dp[105][105][105][2];

int main()
{
    n=read(); s1=(n+1)/2; s2=n-s1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]&1) s1--;
        else if(a[i]) s2--;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][s1][s2][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                for(int bl=0;bl<2;bl++){
                    if(a[i]) checkmin(dp[i][j][k][a[i]&1],dp[i-1][j][k][bl]+((bl^(a[i]&1))&&(i!=1)));
                    else{
                        checkmin(dp[i][j][k][0],dp[i-1][j][k+1][bl]+(bl&&(i!=1)));
                        checkmin(dp[i][j][k][1],dp[i-1][j+1][k][bl]+((bl^1)&&(i!=1)));
                    }
                }
            }
        }
    }
    cout<<min(dp[n][0][0][0],dp[n][0][0][1])<<endl;
    return 0;
}