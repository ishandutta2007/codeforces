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
ll T,n,k,b,s;
void solve(){
    cin>>n>>k>>b>>s;
    ll D=s-k*b;
    if(D<0 || D>(k-1)*n){
        cout<<"-1\n";return;
    }
    ll rest=D;
    cout<<b*k+min(rest,k-1)<<" ";
    rest-=min(rest,k-1);
    rep(i,2,n){
        cout<<min(rest,k-1)<<" ";
        rest-=min(rest,k-1);
    }
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;while(T--)solve();

    return 0;
}