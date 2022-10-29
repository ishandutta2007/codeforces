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
const int N=1005;
vector<pii> v[N];
int n,in[N],tmp[N],id[N],Rt,son[N],deg[N];

struct node{
    int x,y,z;
};
vector<node> ans;

pii fa[N];

void jump(int u,int val){
    while(u!=Rt) fa[u].second-=val,u=fa[u].first;
}
void dfs(int u,int f){
    son[u]=u; vector<pii> G; G.clear();
    for(auto &to : v[u]){
        if(to.first==f) continue;
        G.push_back(to); 
        fa[to.first]=mk(u,to.second);
        deg[u]++; dfs(to.first,u);
        son[u]=son[to.first];
    }
    v[u]=G;
    int val=fa[u].second;
    if(u!=Rt){
        if(deg[u]){
            int son1=son[v[u][0].first],son2=son[v[u][1].first];
            ans.push_back({son1,son2,-val/2});
            ans.push_back({Rt,son1,val/2});
            ans.push_back({Rt,son2,val/2});
            jump(son1,val/2); jump(son2,val/2);
        }
        else ans.push_back({Rt,u,val}),jump(u,val);
    }
}


int main()
{
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read(),z=read();
        v[x].push_back(mk(y,z));
        v[y].push_back(mk(x,z));
        in[x]++; in[y]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==2){
            puts("NO");
            return 0;
        }
        else if(in[i]==1) Rt=i;
    }
    //puts("NO");
    puts("YES"); dfs(Rt,-1);
    printf("%d\n",(int)ans.size());
    for(auto &to : ans) printf("%d %d %d\n",to.x,to.y,to.z);
    return 0;
}