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
const int N=200005;
const int M=1000005;
int n,m,k,a[N];
int fa[M],pos[N];
map<pii,int> mp;
void build1(int x,int l,int r){
    mp[mk(l,r)]=x;
    if(l==r) {pos[l]=x; return;}
    int mid=(l+r)>>1;
    build1(x<<1,l,mid); build1(x<<1|1,mid+1,r);
}
int dp[M][4];

int main()
{
    m=read(); k=read(); n=(1<<m);
    build1(1,1,n);
    memset(dp,0xc0,sizeof(dp));
    for(int i=1;i<=n+n;i++) dp[i][0]=0;
    for(int i=1;i<=k;i++){
        a[i]=read(); int x=pos[a[i]]>>1;
        dp[x][3]=dp[x][1]; dp[x][1]=dp[x][2]=1;
    }
    for(int i=mp[mk(1,2)]-1;i>=1;i--){
        for(int x=0;x<4;x++){
            for(int y=0;y<4;y++) if(x|y){
                int p=x|y,tmp=dp[i<<1][x]+dp[i<<1|1][y];
                if(p==1) checkmax(dp[i][1],tmp+2);
                else if(p==3) checkmax(dp[i][3],tmp+3);
                else if(x==2&&y==2) checkmax(dp[i][3],tmp+2);
                else checkmax(dp[i][2],tmp+1),checkmax(dp[i][1],tmp+2);
            }
        }
    }
    int ret=max(max(0,dp[1][1]+1),max(dp[1][2]+1,dp[1][3]+1));
    cout<<ret<<endl;
    return 0;
}