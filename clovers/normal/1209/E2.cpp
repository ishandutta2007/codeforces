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
const int N=2005;
const int M=4100;
int a[13][N],mx[N],id[N],f[13][M],dp[13][M],n,m;
bool cmp(int x,int y){return mx[x]>mx[y];}

int main()
{
    int T=read();
    while(T--){
        n=read(); m=read();
        memset(a,0,sizeof(a));
        memset(mx,0,sizeof(mx));
        memset(id,0,sizeof(id));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) a[i][j]=read();
        }
        for(int j=1;j<=m;j++){
            id[j]=j; mx[j]=0;
            for(int i=1;i<=n;i++) checkmax(mx[j],a[i][j]);
        }
        sort(id+1,id+m+1,cmp);
        memset(f,0,sizeof(f));
        int full=(1<<n)-1;
        for(int t=1;t<=n;t++){
            int j=id[t];
            for(int S=0;S<=full;S++){
                for(int r=0;r<n;r++){
                    int sum=0;
                    for(int i=1;i<=n;i++) if(S>>(i-1)&1){
                        sum+=a[(i+r-1)%n+1][j];
                    }
                    checkmax(f[t][S],sum);
                }
            }
        }
        memset(dp,0,sizeof(dp));
        for(int t=1;t<=n;t++){
            for(int S=0;S<=full;S++){
                for(int s=S;;s=(s-1)&S){
                    checkmax(dp[t][S],dp[t-1][S^s]+f[t][s]);
                    if(!s) break;
                }
            }
        }
        printf("%d\n",dp[n][full]);
    }
    return 0;
}