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
const ll MAXN=2e5+10,INF=1e18;
ll n,v[MAXN],q,sum,lim;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>v[i],sum+=v[i],lim=max(lim,(sum+i-1)/i);
    cin>>q;
    rep(i,1,q){
        ll num;cin>>num;
        if(num<lim)cout<<-1<<'\n';
        else cout<<(sum+num-1)/num<<'\n';
    }
    return 0;
}