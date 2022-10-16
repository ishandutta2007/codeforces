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
const int MAXN=1e6+10;
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
ll T,n,m,a[MAXN],b,g;
ll ans;
void calc(){
    ll ret=0,ret2=0;
    rep(i,1,g){
        ll sum=0,cnt=0,minabs=1e18;
        rep(j,0,n){
            int pos=i+j*g;
            if(pos>n)break;
            sum+=abs(a[pos]);
            if(a[pos]<0){
                cnt++;
            }
            minabs=min(minabs,abs(a[pos]));
        }
        if(even(cnt))ret+=sum,ret2+=sum-2*minabs;
        else ret+=sum-2*minabs,ret2+=sum;
    }
    ans=max(ret,ret2);
}
void solve(){
    scanf("%lld%lld",&n,&m);
    rep(i,1,n)scanf("%lld",&a[i]);
    scanf("%lld",&g);
    rep(i,1,m-1){
        scanf("%lld",&b);
        g=gcd(g,b);
    }
    if(g==1){
        ans=0;rep(i,1,n)ans+=abs(a[i]);
        printf("%lld\n",ans);return;
    }
    ans=-1e18;
    calc();
    printf("%lld\n",ans);
}
int main(){
    scanf("%lld",&T);
    while(T--)solve();

    return 0;
}