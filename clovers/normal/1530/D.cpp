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
const int N=200005;
int T,n,a[N],b[N],vis[N];
vector<int> v;

int main()
{
    T=read();
    while(T--){
        n=read(); v.clear(); int ans=0;
        for(int i=1;i<=n;i++) a[i]=read(),b[i]=0,vis[i]=0;
        for(int i=1;i<=n;i++) if(!vis[a[i]]) b[i]=a[i],vis[a[i]]=1,ans++;
        for(int i=1;i<=n;i++) if(!b[i]&&!vis[i]) v.push_back(i),vis[i]=1;
        if(ans==n-1&&sz(v)){
            b[v[0]]=a[v[0]]; 
            for(int i=1;i<=n;i++) if(i!=v[0]&&a[i]==a[v[0]]) b[i]=v[0];
            printf("%d\n",ans);
            for(int i=1;i<=n;i++) printf("%d ",b[i]); puts("");
            continue;
        }
        if(sz(v)==1){
            for(int i=1;i<=n;i++) if(i!=v[0]&&!b[i]) {b[i]=v[0]; break;}
            for(int i=1;i<=n;i++) if(!vis[i]) {b[v[0]]=i,vis[i]=1; break;}
            v.clear();
        }
        for(int i=0;i<sz(v);i++) b[v[i]]=v[(i+1)%sz(v)];
        v.clear(); 
        for(int i=1;i<=n;i++) if(!vis[i]) v.push_back(i);
        for(int i=1;i<=n;i++) if(!b[i]) b[i]=v.back(),v.pop_back();
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) printf("%d ",b[i]); 
        puts("");
    }
    return 0;
}