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
const int N=505;
int n,m; ll ans=0;
bitset<N> dp[4][61][N],tmp;
ll t[62][N][2];
ll dfs(int u,int bit,int flag){
    if(t[bit][u][flag]!=-1) return t[bit][u][flag];
    ll ret=0;
    for(int i=bit-1;i>=0;i--){
        int tt=0;
        for(int to=1;to<=n;to++){
            if(dp[flag][i][u].test(to)){
                tt=1;
                checkmax(ret,dfs(to,i,flag^1));
            }
        }
        if(tt){ret+=(1ll<<i); break;}
    }
    return t[bit][u][flag]=ret;
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),w=read();
        dp[w][0][x].set(y);
        dp[w+2][0][y].set(x);
    }
    for(int rnd=1;rnd<=60;rnd++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                tmp=dp[0][rnd-1][i]&dp[3][rnd-1][j];
                if(tmp.any()) dp[0][rnd][i].set(j),dp[2][rnd][j].set(i);
                tmp=dp[1][rnd-1][i]&dp[2][rnd-1][j];
                if(tmp.any()) dp[1][rnd][i].set(j),dp[3][rnd][j].set(i);
            }
        }
    }
    memset(t,-1,sizeof(t));
    ans=dfs(1,61,0);
    if(ans>1e18){puts("-1");}
    else cout<<ans<<endl;
    return 0;
}