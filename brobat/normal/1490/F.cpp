#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> n;
    ll arr[n];
    forn(i, n) cin >> arr[i];
    map<ll, ll> m;
    forn(i, n) m[arr[i]] += 1;
    vector<ll> v;
    for(auto i: m) v.push_back(i.second);
    sort(v.begin(), v.end());
    ll s = v.size();
    // forn(i, s) cout << v[i] << " ";
    ll sum_left[s];
    sum_left[0] = v[0];
    forn(i, s-1) sum_left[i+1] = sum_left[i] + v[i+1];
    ll sum_right[s];
    sum_right[s-1] = v[s-1];
    for(ll i=s-2; i>=0; i--) sum_right[i] = sum_right[i+1] + v[i];
    // forn(i, s) cout << sum_left[i] << " " << sum_right[i] << endl;
    ll left[s];
    left[0] = 0;
    for(ll i=1; i<s; i++) {
        if(v[i]==v[i-1]) left[i] = left[i-1];
        else left[i] = sum_left[i-1];
    }
    ll right[s];
    right[s-1] = 0;
    for(ll i=s-2; i>=0; i--) {
        if(v[i]==v[i+1]) right[i] = right[i+1];
        else right[i] = sum_right[i+1] - v[i]*(s-i-1);
    }
    // forn(i, s) cout << left[i] << " " << right[i] << endl;
    ll ans = BIGINF;
    forn(i, s) ans = min(ans, left[i]+right[i]);
    cout << ans << endl;
}
    return 0;
}