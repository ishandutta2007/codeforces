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
int pre[N],nxt[N];
int n,a[N],vis[N];
void del(int x){vis[x]=1; pre[nxt[x]]=pre[x]; nxt[pre[x]]=nxt[x];}
ll ans=0;

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    for(int i=0;i<=n+1;i++) pre[i]=i-1,nxt[i]=i+1;
    a[0]=0; a[n+1]=0;
    queue<int> q;
    for(int i=1;i<=n;i++) if(a[i]<=a[i+1]&&a[i]<=a[i-1]) q.push(i),vis[i]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        int x=pre[u],y=nxt[u]; del(u);
        ans+=min(a[x],a[y]);
        if(x&&a[x]<=a[y]&&a[x]<=a[pre[x]]) if(!vis[x]) q.push(x),vis[x]=1;
        if(y!=n+1&&a[y]<=a[x]&&a[y]<=a[nxt[y]]) if(!vis[y]) q.push(y),vis[y]=1;
    }
    int x=nxt[nxt[0]];
    while(nxt[x]<=n){
        ans+=min(a[pre[x]],a[nxt[x]]);
        x=nxt[x];
    }
    cout<<ans<<endl;
    return 0;
}