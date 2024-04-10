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
const int M=605;
pii E[M];
int n,m,dis[N][N],d[N],deg[N],rt;
vector<int> v[N];
int bfs(int s){
    int now=s;
    memset(deg,0,sizeof(deg));
    while(now!=rt){
        int fa=0; deg[now]=1;
        for(auto &to : v[now])if(d[to]<d[now]){
            if(fa) return 0;
            fa=to;
        }
        now=fa;
    }
    int ans=1;
    for(int i=1;i<=m;i++){
        int x=E[i].first,y=E[i].second;
        if(d[x]>d[y]) swap(x,y);
        if(d[y]-d[x]==1&&dis[s][y]-dis[s][x]==1) deg[y]++;
    }
    for(int i=1;i<=n;i++) if(i!=rt) Mul(ans,deg[i]);
    return ans;
}

int main()
{
    n=read(); m=read();
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        E[i].first=read(); E[i].second=read();
        dis[E[i].first][E[i].second]=1; dis[E[i].second][E[i].first]=1;
        v[E[i].first].push_back(E[i].second); v[E[i].second].push_back(E[i].first);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) checkmin(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    for(int i=1;i<=n;i++){
        rt=i;
        for(int j=1;j<=n;j++) d[j]=dis[i][j];
        for(int j=1;j<=n;j++){
            printf("%d ",bfs(j));
        } puts("");
    }
    return 0;
}