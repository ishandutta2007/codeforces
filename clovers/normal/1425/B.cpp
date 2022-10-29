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
const int MOD=1e9+7;
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
const int M=3000;
int dp[2][N<<1][2],f[N][N<<1][2];
int n,m,a[N],top=0,vis[N]; 
vector<int> v[N];
void dfs(int u){vis[u]=1; a[top]++; for(auto &to : v[u]) if(!vis[to]) dfs(to);}

int main()
{   
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    vis[1]=1;
    for(auto &to : v[1]) if(!vis[to]){
        top++; dfs(to);
        a[top]++;
    }
    dp[0][M][0]=1; f[0][M][0]=1;
    int sum=0,cur;
    for(int i=1;i<=top;i++){
        cur=i&1;
        memset(dp[cur],0,sizeof(dp[cur]));
        memset(f[cur],0,sizeof(f[cur]));
        for(int j=M-sum;j<=M+sum;j++){
            for(int bl=0;bl<2;bl++){
                Add(dp[cur][j-a[i]][bl],dp[cur^1][j][bl]);
                Add(dp[cur][j+a[i]][bl],dp[cur^1][j][bl]);
                Add(dp[cur][j][bl],dp[cur^1][j][bl]);

                Add(f[cur][j-a[i]][bl],f[cur^1][j][bl]);
                Add(f[cur][j+a[i]][bl],f[cur^1][j][bl]);
            }
            for(int x=1;x<a[i];x++){
                int y=a[i]-x;
                Add(dp[cur][j-x+y][1],mul(2,dp[cur^1][j][0]));
            }
            for(int x=1;x<a[i]-1;x++){
                int y=a[i]-1-x;
                Add(dp[cur][j-x+y][1],mul(2,dp[cur^1][j][0]));
            }
            Add(f[cur][j+a[i]-1][1],mul(2,f[cur^1][j][0]));
            Add(f[cur][j-a[i]+1][1],mul(2,f[cur^1][j][0]));
        }
        sum+=a[i];
    }
    int ans=add(dp[cur][M][1],add(f[cur][M][0],f[cur][M][1]));
    cout<<ans<<endl;
    return 0;
}