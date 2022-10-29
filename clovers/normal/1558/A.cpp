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
int T,a,b,vis[N];

int main()
{
    T=read();
    while(T--){
        a=read(); b=read();
        int n=a+b;
        for(int i=0;i<=n;i++) vis[i]=0;
        int x=n/2,y=n-x;
        int l=max(0,a-x)+max(0,b-y),r=min(a,y)+min(b,x);
        for(int i=l;i<=r;i+=2) vis[i]=1;
        swap(x,y);
        l=max(0,a-x)+max(0,b-y),r=min(a,y)+min(b,x);
        for(int i=l;i<=r;i+=2) vis[i]=1;
        int ans=0;
        for(int i=0;i<=n;i++) ans+=vis[i];
        printf("%d\n",ans);
        for(int i=0;i<=n;i++) if(vis[i]) printf("%d ",i); puts("");
    }
    return 0;
}