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
const int N=100005;
const int K=40;
int n,m;
struct Basis{
    int a[5];
    bool insert(int x){
        for(int i=4;i>=0;i--) if(x>>i&1){
            if(a[i]) x^=a[i];
            else{
                a[i]=x;
                for(int j=0;j<i;j++) if(a[i]>>j&1) a[i]^=a[j];
                for(int j=i+1;j<=4;j++) if(a[j]>>i&1) a[j]^=a[i];
                return 1;
            }
        }
        return 0;
    }
    int Hash(){return a[0]|a[1]<<1|a[2]<<3|a[3]<<6|a[4]<<10;}
    void init(int x){
        a[0]=x&1; a[1]=x>>1&3;
        a[2]=x>>3&7; a[3]=x>>6&15;
        a[4]=x>>10&31;
    }
};
int hcy;
Basis merge(Basis A,Basis B){
    Basis C=B; hcy=1;
    for(int i=0;i<=4;i++) if(A.a[i]) hcy&=C.insert(A.a[i]);
    return C;
}
int id[N],rk[N],top=0;
void dfsB(Basis B){
    int num=B.Hash();
    if(!rk[num]) id[++top]=num,rk[num]=top;
    else return;
    for(int i=1;i<=31;i++){
        Basis C=B;
        hcy=C.insert(i);
        dfsB(C);
    }
}

int spe[N],vis[N],match[N],f[N],g[N],link[N],dep[N]; 
vector<pii> v[N];
Basis dp[N];
void dfs(int u,int from,int fa){
    vis[u]=1;
    for(auto &to : v[u]) if(to.first!=fa){
        if(!vis[to.first]){
            if(spe[to.first]!=-1){
                match[from]=to.first;
                link[from]=to.second; link[to.first]=to.second;
                match[to.first]=from;
            }
            g[to.first]=g[u]^to.second; dep[to.first]=dep[u]+1;
            dfs(to.first,from,u);
            dp[u]=merge(dp[u],dp[to.first]);
            f[u]&=hcy; f[u]&=f[to.first];
        }
        else{
            if(to.first==1||dep[to.first]>=dep[u]) continue;
            int val=g[to.first]^g[u];
            hcy=dp[to.first].insert(val^to.second);
            //out(u); out(to.first); outln(hcy);
            f[to.first]&=hcy;
        }
    }
}

void init(){
    Basis B; B.init(0); dfsB(B);
    n=read(); m=read();
    for(int i=1;i<=n;i++) f[i]=1;
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        v[x].push_back(mk(y,z)); v[y].push_back(mk(x,z));
    }
    vis[1]=1;
    memset(spe,-1,sizeof(spe));
    for(auto &to : v[1]) spe[to.first]=to.second;
    for(auto &to : v[1]){
        if(!vis[to.first]) dfs(to.first,to.first,-1);
        if(match[to.first]) 
            f[match[to.first]]=f[to.first],dp[match[to.first]]=dp[to.first];
        //out(to.first); outln(f[to.first]);
    }
}

int foo[2][405];
void solve(){
    memset(vis,0,sizeof(vis));
    foo[0][rk[0]]=1; int cur=0;
    for(auto &to : v[1]) if(!vis[to.first]){
        cur^=1;
        memset(foo[cur],0,sizeof(foo[cur]));
        int x1=to.first;
        vis[x1]=1;
        if(!match[x1]){
            for(int S=1;S<=top;S++) if(foo[cur^1][S]){
                Add(foo[cur][S],foo[cur^1][S]);
                if(f[x1]){
                    Basis now; now.init(id[S]);
                    now=merge(now,dp[x1]);
                    if(hcy) Add(foo[cur][rk[now.Hash()]],foo[cur^1][S]);
                }
            }
        }
        else{
            int x2=match[x1]; vis[x2]=1;
            for(int S=1;S<=top;S++) if(foo[cur^1][S]){
                Add(foo[cur][S],foo[cur^1][S]);
                if(f[x1]){
                    Basis now; now.init(id[S]);
                    now=merge(now,dp[x1]);
                    if(hcy){
                        Add(foo[cur][rk[now.Hash()]],mul(2,foo[cur^1][S]));
                        int tmp=(spe[x1]^spe[x2]^link[x1]);
                        hcy=now.insert(tmp);
                        if(hcy) Add(foo[cur][rk[now.Hash()]],foo[cur^1][S]);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=top;i++) Add(ans,foo[cur][i]);
    cout<<ans<<endl;
}

int main()
{
    init(); solve();
    return 0;
}