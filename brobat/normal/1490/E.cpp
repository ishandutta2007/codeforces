#include <bits/stdc++.h>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
#define ll long long
#define MAXN 200100
#define MOD 1000000007

ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    cin >> n;
    vector<pair<ll, ll>> arr;
    forn(i, n) {
        ll temp;
        cin >> temp;
        arr.push_back({temp, i+1});
    }
    sort(arr.begin(), arr.end());
    ll tot_tokens[n];
    tot_tokens[0] = arr[0].first;
    forn(i, n-1) tot_tokens[i+1] = tot_tokens[i] + arr[i+1].first;
    bool can_win[n];
    forn(i, n) can_win[i] = false;
    can_win[n-1] = true;
    for(ll i=n-2; i>=0; i--) {
        if(tot_tokens[i]>=arr[i+1].first) {
            if(can_win[i+1]) {
                can_win[i] = true;
            }
        }
    }
    vector <ll> v;
    forn(i, n) {
        if(can_win[i]) v.push_back(arr[i].second);
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for(auto it: v) cout << it << " ";
    cout << endl;
}
    return 0;
}