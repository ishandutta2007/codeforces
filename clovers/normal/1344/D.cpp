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
const int N=500005;
int n; ll a[N],k;
ll f(int i,ll x){return a[i]-3ll*x*x+3ll*x-1;}
ll find(int id,ll lim){
    ll l=0,r=1e9,mid,best;
    if(a[id]<lim) return -1;
    while(l<=r){
        mid=(l+r)>>1;
        if(f(id,mid)>=lim) best=mid,l=mid+1;
        else r=mid-1;
    }
    return best;
}

ll c[N],b[N];
bool check(ll mid){
    for(int i=1;i<=n;i++) c[i]=min(a[i],find(i,mid));
    ll tmp=0;
    for(int i=1;i<=n;i++){
        tmp+=c[i];
        if(c[i]<0) return 0;
    }
    if(tmp>=k){
        for(int i=1;i<=n;i++) b[i]=c[i];
        return 1;
    }
    return 0;
}

typedef pair<ll,int> pli;
priority_queue<pli,vector<pli>,greater<pli> > Q;
int main()
{
    n=read(); scanf("%lld",&k);
    for(int i=1;i<=n;i++) a[i]=read();
    ll l=-3e18,r=1e9,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    ll sum=0; for(int i=1;i<=n;i++) sum+=b[i];
    for(int i=1;i<=n;i++) Q.push(mk(f(i,b[i]),i));
    while(sum-->k){
        pii u=Q.top(); Q.pop();
        b[u.second]--;
        Q.push(mk(f(u.second,b[u.second]),u.second));
    }
    for(int i=1;i<=n;i++) printf("%lld ",b[i]);
    return 0;
}