#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int T,n;
ll a[MAXN],b[MAXN];
ll ans;
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i],b[i]=a[i]-a[i-1];
    ans=0;
    rep(i,2,n)if(b[i]<0){
        ll d=abs(b[i]);
        b[i]+=d;
        b[1]-=d;
        ans+=d;
    }else{
        ans+=b[i];
    }
    ans+=abs(b[1]);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}