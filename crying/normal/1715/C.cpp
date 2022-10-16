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
const int MAXN=1e5+10;
ll n,m,a[MAXN],sum;
ll calc(ll x){
    return x*(n-x);
}
void upd(ll x,ll v){
    if(x>1 && a[x]!=a[x-1])sum-=calc(x-1);
    if(x<n && a[x]!=a[x+1])sum-=calc(x);
    a[x]=v;
    if(x>1 && a[x]!=a[x-1])sum+=calc(x-1);
    if(x<n && a[x]!=a[x+1])sum+=calc(x);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n-1)if(a[i]!=a[i+1])sum+=calc(i);
    rep(i,1,m){
        ll pos,v;cin>>pos>>v;
        upd(pos,v);
        cout<<sum+n*(n+1)/2<<"\n";
    }
    return 0;
}