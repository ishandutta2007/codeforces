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
const int N=300005;
int n,m,k; ll a[N],sum=0;
vector<pii> v[N],G[N];
int vis[N],deg[N];
void dfs(int u){
    vis[u]=1;
    for(auto &e : v[u]){
        int to=e.first;
        if(vis[to]) continue;
        vis[to]=1; 
        G[u].push_back(e); G[to].push_back(mk(u,e.second));
        deg[u]++; deg[to]++;
        dfs(to);
    }
}

vector<int> ans1,ans2;
int main()
{
    n=read(); m=read(); k=read();
    for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
    if(sum<1ll*k*(n-1)){puts("NO"); return 0;}
    puts("YES");
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        v[x].push_back(mk(y,i)); v[y].push_back(mk(x,i));
    }
    dfs(1);
    queue<int> q; 
    for(int i=1;i<=n;i++) if(deg[i]==1) q.push(i);
    memset(vis,0,sizeof(vis));
    for(int rnd=1;rnd<n;rnd++){
        int u=q.front(); q.pop();
        vis[u]=1;
        for(auto &e : G[u]) if(!vis[e.first]){
            deg[e.first]--;
            if(deg[e.first]<=1) q.push(e.first); 
            if(a[u]>=k||rnd==n-1) ans1.push_back(e.second),a[e.first]+=a[u]-k;
            else ans2.push_back(e.second);
        }
    }
    for(auto &to : ans1) printf("%d\n",to);
    reverse(ans2.begin(),ans2.end());
    for(auto &to : ans2) printf("%d\n",to);
    return 0;
}