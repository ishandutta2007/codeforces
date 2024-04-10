#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/

int main(){
    untie;
    int n;
    cin>>n;
    vector<int>l(n),r(n);
    rep(i,0,n)cin>>l[i],cin>>r[i];
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    ll ans =0;
    rep (i,0,n)ans += max(l[i],r[i]);
    cout<<ans + n<<endl;
    return 0;
}