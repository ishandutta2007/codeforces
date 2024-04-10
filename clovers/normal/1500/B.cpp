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
ll _abs(ll x){return x<0 ? -x : x;}
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
int n,m,a[N],b[N],posa[N<<1],posb[N<<1];
ll k,c,g;
void exgcd(ll &a,ll &b,int x,int y){
    if(!y){a=1,b=0; return;}
    exgcd(a,b,y,x%y);
    ll aa=a,bb=b;
    a=bb; b=aa-bb*(x/y);
}

ll vis[N];
ll f(int x,int y,ll lim){
    int delta=y-x; 
    if(_abs(delta)%g) return 0;
    ll A,B;
    if(vis[x]!=INF) A=vis[x];
    else{
        exgcd(A,B,n,m);
        A*=delta/g; vis[x]=A;
    }
    ll pos=((1ll*A*n+x-1)%c+c)%c+1;
    if(pos>lim) return 0;
    //out(x); out(y); out(pos); outln((lim-pos)/c+1);
    return (lim-pos)/c+1;
}
ll calc(ll lim){
    ll ret=lim;
    for(int i=1;i<=n;i++){
        if(posb[a[i]]) ret-=f(i,posb[a[i]],lim);
    }
    return ret;
}

signed main()
{
    n=read(); m=read(); scanf("%lld",&k);
    for(int i=1;i<=n;i++) vis[i]=INF;
    g=__gcd(n,m);
    c=1ll*n*m/g;
    for(int i=1;i<=n;i++) a[i]=read(),posa[a[i]]=i;
    for(int i=1;i<=m;i++) b[i]=read(),posb[b[i]]=i;
    //calc(16); return 0;
    ll l=1,r=1e18,mid,best;
    while(l<=r){
        mid=(l+r)>>1;
        if(calc(mid)>=k) r=mid-1,best=mid;
        else l=mid+1;
    }
    cout<<best<<endl;
    return 0;
}