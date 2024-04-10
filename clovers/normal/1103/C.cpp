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
const int N=500005;
int n,m,k,dep[N],fa[N],nleaf[N];
vector<int> v[N];
int tot=1;

void dfs(int u){
    if(dep[u]>=(n+k-1)/k){
        int x=u;
        vector<int> ans;
        while(x) ans.push_back(x),x=fa[x];
        printf("PATH\n%d\n",sz(ans));
        for(auto &u : ans) printf("%d ",u);
        exit(0);
    }
    for(auto &to : v[u]) if(!dep[to]) 
        nleaf[u]=1,fa[to]=u,dep[to]=dep[u]+1,dfs(to);
}

int main()
{
    n=read(); m=read(); k=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    for(int i=1;i<=n;i++) if(!dep[i]) dep[i]=1,dfs(i);
    printf("CYCLES\n");
    for(int i=1;i<=n&&tot<=k;i++) if(!nleaf[i]){
        vector<int> ans;
        if(fa[i]==v[i][0]) swap(v[i][0],v[i][2]);
        if(fa[i]==v[i][1]) swap(v[i][1],v[i][2]);
        int x=v[i][0],y=v[i][1];
        if((dep[i]-dep[x])%3!=2){
            int u=i;
            while(u!=x) ans.push_back(u),u=fa[u];
            ans.push_back(x);
            printf("%d\n",sz(ans));
            for(auto &u : ans) printf("%d ",u); puts("");
            tot++; continue;
        }
        else if((dep[i]-dep[y])%3!=2){
            int u=i;
            while(u!=y) ans.push_back(u),u=fa[u];
            ans.push_back(y);
            printf("%d\n",sz(ans));
            for(auto &u : ans) printf("%d ",u); puts("");
            tot++; continue;
        }
        else{
            if(dep[x]<dep[y]) swap(x,y);
            int u=x;
            while(u!=y) ans.push_back(u),u=fa[u];
            ans.push_back(y);
            ans.push_back(i);
            printf("%d\n",sz(ans));
            for(auto &u : ans) printf("%d ",u); puts("");
            tot++; continue;
        }
    }
    return 0;
}