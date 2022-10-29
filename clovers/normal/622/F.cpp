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
const int N=1000005;
int n,k,down[N],fac[N];
void brute(){
    int ans=0;
    for(int i=1;i<=n;i++) Add(ans,qpow(i,k));
    cout<<ans<<endl;
}
void init(){
    fac[0]=1; for(int i=1;i<=k+2;i++) fac[i]=mul(fac[i-1],i);
    down[0]=1; 
    for(int i=1;i<=k+2;i++) down[i]=mul(down[i-1],n-i);
}
int f[N];
void solve(){
    for(int i=1;i<=k+2;i++) f[i]=add(f[i-1],qpow(i,k)); 
    int ans=0;
    int s2=down[k+2];
    for(int i=1;i<=k+2;i++){
        int tmp1=mul(((k+2-i)&1 ? MOD-1 : 1),mul(fac[i-1],fac[k+2-i]));
        int tmp2=mul(f[i],mul(s2,qpow(n-i,MOD-2)));
        Add(ans,mul(qpow(tmp1,MOD-2),tmp2));
    }
    cout<<ans<<endl;
}

int main()
{
    n=read(); k=read();
    if(n<=k+2){
        brute();
        return 0;
    }
    init(); solve();
    return 0;
}