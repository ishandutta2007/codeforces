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
const int N=405;
char s[N][N];
int n,m,sum[N][N],T,pre[N];

void solve(){
    n=read(); m=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) sum[i][j]=(sum[i][j-1]+s[i][j]-'0');
    }
    int ans=inf;
    for(int l=1;l<=m-3;l++){
        for(int r=l+3;r<=m;r++){
            int now=0,mi=inf;
            for(int i=1;i<=n;i++){
                if(i>=5){
                    checkmin(mi,pre[i-4]);
                    checkmin(ans,mi+now+(r-l-1-(sum[i][r-1]-sum[i][l])));
                }
                now+=sum[i][r-1]-sum[i][l]+(s[i][l]=='0')+(s[i][r]=='0');
                pre[i]=-now+(r-l-1-(sum[i][r-1]-sum[i][l]));
                // out(i); out(pre[i]); outln(now);
            }
        }
    }
    printf("%d\n",ans);
}

int main()
{
    T=read();
    while(T--){solve();}
    return 0;
}