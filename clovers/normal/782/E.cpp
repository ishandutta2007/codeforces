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
const int N=200005;
int n,m,k,vis[N],cnt=0,d;
vector<int> v[N];
vector<int> ans[N];
int now=1;

void dfs(int u){
    vis[u]=1; ans[now].push_back(u); cnt++;
    if(cnt==d){cnt=0; now++;}
    for(auto &to : v[u]){
        if(vis[to]) continue;
        dfs(to); ans[now].push_back(u); cnt++;
        if(cnt==d){cnt=0; now++;}
    }
}

int main()
{
    n=read(); m=read(); k=read(); d=(2*n+k-1)/k;
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=k;i++){
        if(sz(ans[i])==0){
            puts("1 1");
            continue;
        }
        printf("%d ",sz(ans[i]));
        for(auto &u : ans[i]) printf("%d ",u);
        puts("");
    }
    return 0;
}