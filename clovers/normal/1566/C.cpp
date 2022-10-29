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
const int N=100005;
int T,n,a[2][N],dp[N][4],typ[N];
char s[2][N];
int calc(int S){
    if(S%2==0) return 0;
    else return 1+(S==3);
}

int main()
{
    T=read();
    while(T--){
        n=read();
        scanf("%s",s[0]+1); scanf("%s",s[1]+1);
        for(int i=1;i<=n+1;i++) dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=-inf;
        for(int i=1;i<=n;i++){
            typ[i]=0;
            if(s[0][i]=='0'||s[1][i]=='0') typ[i]|=1;
            if(s[0][i]=='1'||s[1][i]=='1') typ[i]|=2;
        }
        dp[1][0]=0;
        for(int i=1;i<=n;i++){
            for(int S=0;S<4;S++) if(dp[i][S]>=0){
                int to=(S|typ[i]);
                checkmax(dp[i+1][to],dp[i][S]);
                checkmax(dp[i+1][0],dp[i][S]+calc(S|typ[i]));
            }
        }
        printf("%d\n",dp[n+1][0]);
    }
    return 0;
}