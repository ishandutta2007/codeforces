#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

ll n, k, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> n >> k >> x;
    ll arr[n];
    forn(i, n) cin >> arr[i];
    sort(arr, arr+n);
    vector <ll> v;
    forn(i, n-1) if(arr[i+1]-arr[i]>x) v.push_back(arr[i+1]-arr[i]);
    sort(v.begin(), v.end());
    ll s= v.size();
    forn(i, s) {
        // cout << v[i] << " ";
        ll temp = (v[i]-1)/x;
        if(temp>k) break;
        v[i] = 0;
        k -= temp;
    }
    ll ans = 1;
    forn(i, s) if(v[i]!=0) ans++;
    // forn(i, s) cout << v[i] << " ";
    cout << ans << endl;
}
    return 0;
}