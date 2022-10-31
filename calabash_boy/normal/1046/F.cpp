#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);


/************* header ******************/


int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    int f,x;
    cin>>f>>x;
    ll ans =0;
    rep(i,0,n)ans += (a[i] -f + f+x-1)/(f+x);
    cout<<ans * x<<endl;
    return 0;
}