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
int n,m,k,deg[N],vis[N],pre[N],bl[N];
vector<int> v[N];
const int MOD1=777787;
struct Hash_Table{
    vector<ll> v[MOD1];
    vector<int> used;
    void clear(){
        for(auto &u : used) v[u].clear();
        used.clear();
    } 
    void insert(ll x){
        if(v[x%MOD1].empty()) used.push_back(x%MOD1);
        v[x%MOD1].push_back(x);
    }
    bool find(ll x){
        for(auto &to : v[x%MOD1]) if(to==x) return 1;
        return 0;
    }
}H;

int main()
{
    int T=read();
    while(T--){
        n=read(); m=read(); k=read();
        for(int i=1;i<=n;i++) v[i].clear(),deg[i]=0,vis[i]=0;
        H.clear();
        for(int i=1;i<=m;i++){
            int x=read(),y=read();
            v[x].push_back(y); v[y].push_back(x);
            deg[x]++; deg[y]++; 
            H.insert(1ll*n*x+y); H.insert(1ll*n*y+x);
        }
        for(int i=1;i<=n;i++) pre[i]=deg[i];

        queue<int> q; while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++) if(deg[i]<k) q.push(i),vis[i]=1;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto &to : v[u]) if(!vis[to]){
                deg[to]--; 
                if(deg[to]<k) q.push(to),vis[to]=1;
            }
        }
        vector<int> ans;
        for(int i=1;i<=n;i++) if(!vis[i]) ans.push_back(i);
        if(sz(ans)){
            printf("1 %d\n",sz(ans));
            for(auto &u : ans) printf("%d ",u);
            puts("");
            continue;
        }
        if(1ll*k*(k-1)/2>m){
            puts("-1");
            continue;
        }

        for(int i=1;i<=n;i++) deg[i]=pre[i],vis[i]=0,bl[i]=0;
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++) if(deg[i]<k) q.push(i),vis[i]=1;
        int ok=0;
        while(!q.empty()){
            int u=q.front(); q.pop(); bl[u]=1;
            if(deg[u]==k-1){
                int flag=1;
                vector<int> tmp;
                for(auto &to : v[u]) if(!bl[to]) tmp.push_back(to);
                tmp.push_back(u);
                for(int i=0;i<sz(tmp);i++){
                    if(!flag) break;
                    for(int j=i+1;j<sz(tmp);j++){
                        if(!H.find(1ll*tmp[i]*n+tmp[j])){
                            flag=0; break;
                        }
                    }
                }
                if(flag){
                    puts("2");
                    for(auto &u : tmp) printf("%d ",u);
                    puts("");
                    ok=1; break;
                }
            }
            for(auto &to : v[u]){
                deg[to]--; 
                if(deg[to]<k&&!vis[to]) q.push(to),vis[to]=1;
            }
        }
        if(!ok) puts("-1");
    }
    return 0;
}