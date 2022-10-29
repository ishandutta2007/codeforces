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
const int N=200005;
map<int,int> mp;
int n,fac[N],ifac[N],ans=1;
int C(int n,int m){return mul(fac[n],mul(ifac[m],ifac[n-m]));}
void calc(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            if(!mp.count(i)) mp[i]=0;
            while(x%i==0) mp[i]++,x/=i;
        }
    }
    if(x!=1) if(!mp.count(x)) mp[x]=1; else mp[x]++; 
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        int x=read();
        calc(x);
    }
    fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
    ifac[N-1]=qpow(fac[N-1],MOD-2);
    for(int i=N-2;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    for(auto &u : mp){
        Mul(ans,C(u.second+n-1,n-1));
    }
    cout<<ans<<endl;
    return 0;
}