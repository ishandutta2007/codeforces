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
const int N=3005;
char s[N],t[N];
int n,m;
int dp[N][N];

int main()
{
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1); m=strlen(t+1);
    for(int i=1;i<=n;i++){
        if(i>m||t[i]==s[1]) dp[i][i]=2;
    }
    for(int len=1;len<n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            if(l-1>m||t[l-1]==s[len+1]) Add(dp[l-1][r],dp[l][r]);
            if(r+1>m||t[r+1]==s[len+1]) Add(dp[l][r+1],dp[l][r]);
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++) Add(ans,dp[1][i]);
    cout<<ans<<endl;
    return 0;
}