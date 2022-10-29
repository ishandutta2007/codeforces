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
#define int long long
const int N=100005;
int n,sz[N]; vector<int> v[N];
struct Edge{
    int from,to,cost;
}E[N];
void dfs(int u,int f){
    sz[u]=1;
    for(auto &to : v[u]) if(to!=f) dfs(to,u),sz[u]+=sz[to];
}
double ans=0; int C3;
int C2(int x){return x*(x-1)/2;}

signed main()
{
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read(),z=read();
        v[x].push_back(y); v[y].push_back(x);
        E[i]={x,y,z};
    }
    dfs(1,-1);
    C3=n*(n-1)*(n-2)/6;
    for(int i=1;i<n;i++){
        int x=E[i].from,y=E[i].to;
        int szx=min(sz[x],sz[y]),szy=n-szx;
        ans+=1.0*(C2(szx)*szy+C2(szy)*szx)*2*E[i].cost/C3;
    }
    int m=read();
    while(m--){
        int i=read(),w=read();
        int x=E[i].from,y=E[i].to;
        int szx=min(sz[x],sz[y]),szy=n-szx;
        ans-=1.0*(C2(szx)*szy+C2(szy)*szx)*2*E[i].cost/C3;
        E[i].cost=w;
        ans+=1.0*(C2(szx)*szy+C2(szy)*szx)*2*E[i].cost/C3;
        printf("%.9lf\n",ans);
    }
    return 0;
}