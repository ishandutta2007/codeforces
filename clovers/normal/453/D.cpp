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
ll MOD=998244353;
ll add(ll x,ll y){x+=y; return x>=MOD ? x-MOD : x;}
ll sub(ll x,ll y){x-=y; return x<0 ? x+MOD : x;}
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
const int N=1100005;

ll msc(ll A,ll B){
    ll v=(A*B-(ll)((long double)A/MOD*B+1e-8)*MOD);
    return v<0 ? v+MOD : v;
}

void FWT_xor(int len,ll *a,int flag){
    for(int h=1;h<len;h<<=1){
        for(int i=0;i<len;i+=(h<<1)){
            for(int j=i;j<i+h;j++){
                ll x=a[j],y=a[j+h];
                a[j]=add(x,y); a[j+h]=sub(x,y);
            }
        }
    }
    if(flag==-1){
        for(int i=0;i<len;i++) a[i]/=len;
    }
}

ll n,m,t;
ll b[N],f[N],g[N];
int calc(ll x){
    int ret=0;
    for(ll i=0;i<m;i++) ret+=(x>>i&1);
    return ret;
}

ll ksm(ll x,ll y){
    ll ret=1;
    while(y){
        if(y&1) ret=msc(ret,x);
        x=msc(x,x);
        y>>=1;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld%lld",&m,&t,&MOD); 
    n=(1ll<<m); MOD*=n;
    for(int i=0;i<n;i++) f[i]=read();
    for(int i=0;i<=m;i++) b[i]=read();
    for(int i=0;i<n;i++) g[i]=b[calc(i)];
    //for(int i=0;i<n;i++) cout<<f[i]<<" "; cout<<endl;
    //for(int i=0;i<n;i++) cout<<g[i]<<" "; cout<<endl;
    FWT_xor(n,f,1); FWT_xor(n,g,1);
    for(int i=0;i<n;i++) g[i]=ksm(g[i],t);    
    for(int i=0;i<n;i++) g[i]=msc(g[i],f[i]);
    FWT_xor(n,g,-1);
    for(int i=0;i<n;i++) printf("%lld\n",g[i]);
    return 0;
}