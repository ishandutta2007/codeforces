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
const ll MAXN=2e5+10,INF=8e18;
ll T,n,a[MAXN],ans;
ll K,B;
void solve(ll k,ll b,ll L,ll R){
    if(ans==INF)return;
    if(k==0)ans=max(ans,b);
    else if(k>0){
        if(R==INF)ans=INF;
        else ans=max(ans,k*R+b);
    }else{
        if(L==-INF)ans=INF;   
        else ans=max(ans,k*L+b);
    }
}
void solve(){
    cin>>n;ans=-INF;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    ll K=0,B=0;
    rep(i,1,n-1)K+=a[i]+a[n],B+=a[i]*a[n];
    solve(K,B,-INF,-a[n]);
    per(i,n,2){
        //i
        if(i!=n)K-=(a[i]+a[n]),B-=a[i]*a[n];
        K+=a[i]+a[1];B+=a[i]*a[1];
        solve(K-a[1]-a[n],B-a[1]*a[n],-a[i],-a[i-1]);
    }
    K=0;B=0;
    rep(i,2,n)K+=a[i]+a[1],B+=a[i]*a[1];
    solve(K,B,-a[1],INF);
    if(ans==INF)cout<<"INF\n";
    else cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;while(T--)solve();

    return 0;
}