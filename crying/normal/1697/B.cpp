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
int n,q,p[MAXN];
ll sum[MAXN];
int main(){
    cin>>n>>q;
    rep(i,1,n)cin>>p[i];
    sort(p+1,p+1+n);
    rep(i,1,n)sum[i]=sum[i-1]+p[i];
    rep(i,1,q){
        ll x,y;cin>>x>>y;
        cout<<sum[n-(x-y)]-sum[n-x]<<'\n';
    }


    return 0;
}