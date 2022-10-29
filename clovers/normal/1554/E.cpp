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
const int N=1000005;
int n,first[N],nxt[N<<1],point[N<<1],bl[N],e=0;
void add_edge(int x,int y){
    point[e]=y; nxt[e]=first[x]; first[x]=e++;
}
int k,now,flag;
int dfs(int u,int f){
    int deg=0;
    for(int i=first[u];i!=-1;i=nxt[i]) 
        if(point[i]!=f) deg+=dfs(point[i],u);
    if(deg%k==0){
        now=__gcd(now,deg);
        return 1;
    }
    else if((deg+1)%k==0){
        now=__gcd(now,deg+1);
        return 0;
    }
    else{flag=0; return 0;}
}

int ret[N];
void solve(){
    n=read(); e=0; for(int i=1;i<=n;i++) first[i]=-1,ret[i]=0;
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y); add_edge(y,x);
    }
    ret[1]=qpow(2,n-1);
    for(int i=2;i<n;i++) if((n-1)%i==0&&!bl[i]){
        k=i; now=0; flag=1; dfs(1,-1);
        if(flag) ret[now]=1;
    }
    for(int i=2;i<n;i++) Sub(ret[1],ret[i]);
    for(int i=1;i<=n;i++) printf("%d ",ret[i]); puts("");
}

int main()
{
    n=1000000;
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i) bl[j]=1;
    }
    int T=read();
    while(T--){solve();}
    return 0;
}