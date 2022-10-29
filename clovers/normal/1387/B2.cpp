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
const int N=100005;
int n,mat[N],sz[N],rt,mi=inf;
vector<int> seq,v[N];
ll ans=0;

void dfs0(int u,int f){
    sz[u]=1; int mx=0;
    for(auto &to : v[u]) if(to!=f){
        dfs0(to,u);
        checkmax(mx,sz[to]); sz[u]+=sz[to];
    }
    if(mi>max(mx,n-sz[u])) mi=max(mx,n-sz[u]),rt=u;
}

void dfs(int u,int f){
    seq.push_back(u); ans+=min(n-sz[u],sz[u]);
    for(auto &to : v[u]) if(to!=f) dfs(to,u);
}

int main()
{
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs0(1,-1); dfs(rt,-1);
    for(int i=0;i<sz(seq);i++) mat[seq[i]]=seq[(i+n/2)%n];
    cout<<ans*2<<endl;
    for(int i=1;i<=n;i++) printf("%d ",mat[i]);
    return 0;
}