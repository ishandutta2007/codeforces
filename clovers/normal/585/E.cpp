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
const int N=500005;
const int V=10000005;
int f[V],g[V],prime[N<<1],mu[V],tot=0;
bool bl[V];
void init(int n){
    for(int i=2;i<=n;i++){
        if(!bl[i]) prime[++tot]=i,mu[i]=1;
        for(int j=1;j<=tot;j++){
            if(prime[j]*i>n) break;
            bl[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            mu[i*prime[j]]=(MOD-mu[i])%MOD;
        }
    }
}

int n,a[N],Base[N],m=0;
int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),f[a[i]]++,checkmax(m,a[i]);
    init(m);
    for(int i=1;i<=tot;i++){
        for(int j=m/prime[i],k=j*prime[i];j>=1;j--,k-=prime[i]){
            Add(f[j],f[k]);
        }
    }
    Base[0]=1; for(int i=1;i<=n;i++) Base[i]=mul(Base[i-1],2);
    for(int i=2;i<=m;i++){
        for(int j=i;j<=m;j+=i) Add(g[j],mul(mu[i],f[i]));
    }
    for(int i=2;i<=m;i++) g[i]=sub(n,g[i]),f[i]=sub(Base[f[i]],1);
    for(int i=m;i>=2;i--){
        for(int j=i+i;j<=m;j+=i) Sub(f[i],f[j]);
    }
    int ans=0;
    for(int i=2;i<=m;i++){
        Add(ans,mul(f[i],g[i]));
    }
    cout<<ans<<endl;
    return 0;
}