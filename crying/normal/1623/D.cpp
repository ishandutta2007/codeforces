#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const ll MAXN=1e5+10,mod=1e9+7;
ll mypow(ll a,ll n){if(!n)return 1;ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;if(n&1)tmp=tmp*a%mod;return tmp;}
ll D(ll a,ll b){return a*mypow(b,mod-2)%mod;}
ll g(ll x){return D(1,(mod+1-x));}
ll f(ll x){return (D(1,(mod+1-x)*(mod+1-x)%mod)-g(x)+mod)%mod;}
int T,n,m,sx,sy,ex,ey,fdx,fdy;
ll S,C,omega1,omega2,p,rp;
void dfs(int x,int y,int dx,int dy,int step){
    if(x+dx<1||x+dx>n)dx=-dx;
    if(y+dy<1||y+dy>m)dy=-dy;
    if(!step)fdx=dx,fdy=dy;
    if(x==sx&&y==sy&&step&&dx==fdx&&dy==fdy)return;
    S++;
    if(x==ex||y==ey){
        ll val=mypow(rp,C);
        omega1=(omega1+val)%mod;
        omega2=(omega2+val*step%mod)%mod;
        C++;
    }
    dfs(x+dx,y+dy,dx,dy,step+1);
}
void solve(){
    cin>>n>>m>>sx>>sy>>ex>>ey;
    cin>>p;rp=D(100-p,100);p=D(p,100);
    S=0,C=0,omega1=0,omega2=0;
    dfs(sx,sy,1,1,0);
    ll s1=f(mypow(rp,C)),s2=g(mypow(rp,C));
    ll ans=(S*omega1%mod*s1%mod+omega2*s2%mod)%mod*p%mod;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}