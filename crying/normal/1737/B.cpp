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
ll T,l,r;
ll f(ll x){
    ll res=1;
    res*=((x+1)/3);
    res*=((x/3)+1);
    res+=(x+2)/3;
    return res;
}
ll g(ll t){
    ll l=0,r=4e9;
    while(l<r){
        ll mid=(l+r+1)/2;
        if(f(mid)>t)r=mid-1;
        else l=mid;
    }
    return l;
}
void solve(){
    cin>>l>>r;
    cout<<g(r)-g(l-1)<<"\n";

}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}