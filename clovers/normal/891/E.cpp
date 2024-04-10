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
const int N=5005;
int n,k,a[N];
int f[N],g[N],down[N];

int main()
{
    n=read(); k=read();
    for(int i=1;i<=n;i++) a[i]=read();
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--) f[j]=sub(mul(f[j],a[i]),f[j-1]);
        Mul(f[0],a[i]);
    }
    down[0]=1; for(int i=1;i<=n;i++) down[i]=mul(down[i-1],k-i+1);
    for(int i=0;i<=min(n,k);i++) g[i]=mul(qpow(n,k-i),down[i]);
    int S1=1,S2=0;
    for(int i=0;i<=n;i++) Add(S2,mul(f[i],g[i]));
    Mul(S2,qpow(qpow(n,k),MOD-2));
    for(int i=1;i<=n;i++) Mul(S1,a[i]);
    cout<<sub(S1,S2)<<endl;
    return 0;
}