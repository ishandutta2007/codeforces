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

ll calc(ll x){
    ll res = 0;
    while (x){
        res += x%10;
        x /=10;
    }
    return res;
}
int main(){
    untie;
    ll n;
    cin>>n;
    if (n<10){
        cout<<n<<endl;
        exit(0);
    }
    ll temp = 9;
    while (temp*10 + 9 <= n){
        temp = temp*10 +9;
    }
    ll ans = calc(temp) + calc(n- temp);
    cout<<ans<<endl;
    return 0;
}