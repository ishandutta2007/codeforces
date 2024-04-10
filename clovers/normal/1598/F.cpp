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
const int N=25;
const int M=400005;
int n,len[N],mi[N],num[N][M],sum[N];
char s[N][M];
int dp[1<<20],ans=0;
bool bl[1<<20];

int main()
{
    n=read(); 
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        len[i]=strlen(s[i]+1);
        for(int j=1;j<=len[i];j++){
            sum[i]+=(s[i][j]=='(' ? 1 : -1);
            if(sum[i]<mi[i]) mi[i]=sum[i],num[i][-mi[i]]=1;
            else if(sum[i]==mi[i]) num[i][-mi[i]]++;
        }
    }
    int full=(1<<n)-1; bl[0]=1;
    for(int S=0;S<=full;S++) if(bl[S]){
        int s=0; checkmax(ans,dp[S]);
        for(int i=1;i<=n;i++) if(S>>(i-1)&1) s+=sum[i];
        for(int i=1;i<=n;i++) if(!(S>>(i-1)&1)){
            int to=S|(1<<(i-1));
            if(mi[i]+s==0) checkmax(dp[to],dp[S]+num[i][s]),bl[to]=1;
            else if(mi[i]+s>0) checkmax(dp[to],dp[S]),bl[to]=1;
            else checkmax(ans,dp[S]+num[i][s]);
        }
    }
    cout<<ans<<endl;
    return 0;
}