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
const int N=100005;
int dp[N][2],n,fa[N],a[N];
vector<int> v[N]; 

void dfs(int u){
    dp[u][a[u]]=1;
    for(auto &to : v[u]){
        dfs(to);
        int tmp1=0,tmp0=0;
        Add(tmp1,mul(dp[u][1],add(dp[to][0],dp[to][1])));
        Add(tmp0,mul(dp[u][0],add(dp[to][0],dp[to][1])));
        Add(tmp1,mul(dp[u][0],dp[to][1]));
        dp[u][1]=tmp1; dp[u][0]=tmp0;
    }
}

int main()
{
    n=read();
    for(int i=2;i<=n;i++){
        fa[i]=read()+1;
        v[fa[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) a[i]=read();
    dfs(1);
    cout<<dp[1][1]<<endl;
    return 0;
}