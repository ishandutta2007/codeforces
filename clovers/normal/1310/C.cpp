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
const ll INF=(ll)1e18+10;
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
const int N=1005;
const int M=N*N;
char s[N];
int n,m,lcp[N][N]; ll k;
__int128_t dp[N][N],sum[N][N];
pii a[M]; int tot=0;
bool cmp(pii a,pii b){
    int len=lcp[a.first][b.first];
    int ra=a.first+len,rb=b.first+len;
    if(ra>a.second||rb>b.second) return a.second-a.first>=b.second-b.first;
    return s[ra]>=s[rb];
}

bool check(pii now){
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m;j++) dp[i][j]=0,sum[j][i]=0;
    dp[n+1][0]=1; sum[0][n+1]=1;
    for(int i=n;i>=1;i--){
        for(int j=1;j+i-1<=n&&j<=m;j++){
            int len=now.second-now.first+1;
            int nxt=i+min(lcp[i][now.first],len);
            if(cmp(mk(i,n),now)){
                if(nxt-i==len) dp[i][j]=sum[j-1][nxt];
                else dp[i][j]=sum[j-1][nxt+1];
            }
            if(dp[i][j]>INF) dp[i][j]=INF;
            sum[j][i]=sum[j][i+1]+dp[i][j];
            //out(i); out(j); outln(dp[i][j]);
        }
        sum[0][i]=1;
    }
    return dp[1][m]>=k;
}

int main()
{
    n=read(); m=read(); scanf("%lld",&k);
    scanf("%s",s+1);
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
            else lcp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) a[++tot]=mk(i,j);
    }
    sort(a+1,a+tot+1,cmp);
    int l=1,r=tot,mid,best;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(a[mid])) r=mid-1,best=mid;
        else l=mid+1;
    }
    for(int i=a[best].first;i<=a[best].second;i++) printf("%c",s[i]);
    return 0;
}