#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

ll a, b;
vector <ll> v;
vector <pair<ll, ll>> ans;

void pd() {
    ll n = b - a;
    for(ll i=1; i<=sqrt(n); i++) {
        if(n%i==0) {
            v.push_back(i);
            v.push_back(n/i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> a >> b;
    if(a > b) swap(a, b);
    if(a==b) {
        cout << 0;
        return 0;
    }
    pd();
    for(auto i: v) {
        ll temp = a - i*(a/i);
        if(temp==0) {
            ans.push_back({a*b/i, 0});
        }
        else {
            ll k = i - temp;
            ans.push_back({(a+k)*(b+k)/i, k});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].second;
}
    return 0;
}