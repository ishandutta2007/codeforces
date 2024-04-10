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
const int N=605;
int dis[N],tmp[N];
int n,m,vis[N];
vector<pii> v[N];
void dijkstra(int from){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[from]=0;
    for(int rnd=1;rnd<=n;rnd++){
        int mi=inf; int pos;
        for(int i=0;i<n;i++) if(!vis[i]&&mi>dis[i]) mi=dis[i],pos=i;
        vis[pos]=1; memset(tmp,0x3f,sizeof(tmp));
        for(auto &e : v[pos]){
            int to=e.first,w=e.second;
            to=(to+dis[pos])%n;
            checkmin(tmp[to],dis[pos]+w);
        }
        for(int i=0;i<n+n;i++) checkmin(tmp[(i+1)%n],tmp[i%n]+1);
        for(int i=0;i<n;i++) checkmin(dis[i],tmp[i]);
    }
    for(int i=0;i<n;i++) printf("%d ",dis[i]); puts("");
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        v[x].push_back(mk(y,z));
    }
    for(int f=0;f<n;f++) dijkstra(f);
    return 0;
}