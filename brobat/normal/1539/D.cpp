#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll unsigned long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> n;
    ll arr[n][2];
    forn(i, n) cin >> arr[i][0] >> arr[i][1];
    ll sum_a = 0;
    ll ans = 0;
    ll rouble_count = 0;
    forn(i, n) sum_a += arr[i][0];
    forn(i, n) {
        if(arr[i][1]>=sum_a) {
            rouble_count += arr[i][0];
            ans += 2*arr[i][0];
            arr[i][0] = 0;
            arr[i][1] = 0;
        }
    }
    // forn(i, n) cout << arr[i][0] << " " << arr[i][1] << endl;
    // cout << rouble_count << endl;
    vector <pair<ll, ll>> v;
    ll s = 0;
    forn(i, n) {if(arr[i][1]>0) {v.push_back({arr[i][1], arr[i][0]}); s++;}}
    sort(v.begin(), v.end());
    deque <pair<ll, ll>> q;
    forn(i, s) q.push_back({v[i].second, v[i].first});
    while(!q.empty()) {
        if(q.front().second <= rouble_count) {
            // cout << q.front().first << " bought at 1 rouble each.";
            rouble_count += q.front().first;
            ans += q.front().first;
            q.pop_front();
        }
        else { 
            ll temp = q.front().second - rouble_count;
            if(q.back().first > temp) {
                rouble_count += temp;
                ans += 2*temp;
                q.back().first -= temp;
            }
            else {
                rouble_count += q.back().first;
                ans += 2*q.back().first;
                q.pop_back();
            }
        }
    }
    cout << ans << endl;
}
    return 0;
}