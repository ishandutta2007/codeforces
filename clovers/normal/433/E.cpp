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
const int N=205;
const int M=505;
int n,m,K,L[N],R[N],s[N];

struct AhoCorasick{
    int tot=1;
    int son[N][30],fail[N],sz[N];
    void insert(int *s,int val){
        int x=1;
        for(int i=1;i<=s[0];i++){
            int to=s[i];
            if(!son[x][to]) son[x][to]=++tot;
            x=son[x][to];
        }
        sz[x]+=val;
    }
    void build(){
        for(int i=0;i<m;i++) son[0][i]=1;
        queue<int> q; fail[1]=0; q.push(1);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int i=0;i<m;i++){
                if(son[u][i]){
                    fail[son[u][i]]=son[fail[u]][i],q.push(son[u][i]);
                    sz[son[u][i]]+=sz[son[fail[u]][i]];
                }
                else son[u][i]=son[fail[u]][i];
            }
        }
    }
    bool checkL(){
        int x=1,ret=0;
        for(int i=1;i<=L[0];i++){
            x=son[x][L[i]];
            ret+=sz[x];
        }
        return ret<=K;
    }
    int dp[N][N][M][2][2];//wei point val ding 0
    int DP(int *a){
        memset(dp,0,sizeof(dp));
        dp[0][1][0][1][1]=1;
        int ret=0;
        for(int i=0;i<=a[0];i++){
            for(int j=1;j<=tot;j++){
                for(int k=0;k<=K;k++){
                    for(int d=0;d<=1;d++){
                        for(int z=0;z<=1;z++) if(dp[i][j][k][d][z]){
                            if(i==a[0]){Add(ret,dp[i][j][k][d][z]); continue;}
                            for(int p=0;p<m;p++){
                                int to=son[j][p];
                                if(d==1&&p>a[i+1]) break;
                                int tmp=dp[i][j][k][d][z];
                                if(z==1&&p==0)
                                    Add(dp[i+1][j][k][0][1],tmp);
                                else{
                                    if(k+sz[to]>K) continue;
                                    Add(dp[i+1][to][k+sz[to]][d&&p==a[i+1]][0],tmp);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
}tree;

void init(){
    n=read(); m=read(); K=read();
    L[0]=read(); for(int i=1;i<=L[0];i++) L[i]=read();
    R[0]=read(); for(int i=1;i<=R[0];i++) R[i]=read();
    for(int i=1;i<=n;i++){
        s[0]=read(); for(int i=1;i<=s[0];i++) s[i]=read();
        int val=read();
        tree.insert(s,val);
    }
}

int main()
{
    init();
    tree.build();
    int ans=sub(tree.DP(R),tree.DP(L));
    Add(ans,tree.checkL());
    cout<<ans<<endl;
    return 0;
}