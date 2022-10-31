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
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0)
#define untie do {ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/


int main(){
    untie;
    int n;
    cin>>n;
    map<int,int> cnt;
    ll ans =0;
    rep(o,0,n){
        string s;
        cin>>s;
        int mask = 0;
        vi a(26,0);
        rep(i,0,s.size()){
            int ch = s[i] - 'a';
            a[ch]^=1;
        }
        rep(i,0,26)if (a[i])mask |= (1<<i);
        ans += cnt[mask];
        rep(i,0,26)ans += cnt[mask^(1<<i)];
        cnt[mask]++;
    }
    cout<<ans<<endl;
    return 0;
}