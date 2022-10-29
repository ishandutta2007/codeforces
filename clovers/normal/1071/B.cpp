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
int dis[N][N],n,k;
char s[N][N],ans[N+N];
int bl[N][N];

int main()
{
    n=read(); k=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    memset(dis,0x3f,sizeof(dis));
    int len=0;
    dis[1][1]=(s[1][1]!='a');
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) if(i!=1||j!=1){
            dis[i][j]=min(dis[i-1][j],dis[i][j-1])+(s[i][j]!='a');
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        if(dis[i][j]<=k) checkmax(len,i+j),bl[i][j]=1;
    }
    if(!len) ans[2]=s[1][1],len=2,bl[1][1]=1;
    else for(int i=2;i<=len;i++) ans[i]='a';
    for(int l=len+1;l<=n+n;l++){
        char mi='z'+1;
        for(int i=1;i<=n;i++){
            int j=l-i;
            if(j<1||j>n) continue;
            if(bl[i-1][j]||bl[i][j-1]){
                mi=min(mi,s[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            int j=l-i;
            if(j<1||j>n) continue;
            if((bl[i-1][j]||bl[i][j-1])&&s[i][j]==mi) bl[i][j]=1;
        }
        ans[l]=mi;
    }
    for(int i=2;i<=n+n;i++) printf("%c",ans[i]);
    return 0;
}