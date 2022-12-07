#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

ll n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> n >> m;
    ll arr[n];
    ll x[m];
    forn(i, n) cin >> arr[i];
    forn(i, m) cin >> x[i];
    ll sum[n];
    sum[0] = arr[0];
    forn(i, n-1) sum[i+1] = sum[i] + arr[i+1];
    // forn(i, n) cout << sum[i] << " ";
    bool inf = false;
    if(sum[n-1]<=0) inf = true;
    ll last = sum[n-1];
    forn(i, n-1) if(sum[i+1]<sum[i]) sum[i+1] = sum[i];
    // forn(i, n) cout << sum[i] << " ";
    vector <ll> v;
    forn(i, n) v.push_back(sum[i]);
    forn(i, m) {
        ll full_loops = 0;
        if(inf && x[i]>sum[n-1]) {
            cout << -1 << " ";
            continue;
        }
        else if(!inf && x[i]>sum[n-1]) {
            ll temp = sum[n-1]/last;
            temp++;
            // Now sum[n-1] is atmost temp times last.
            full_loops += (x[i]/last) - temp;
            x[i] -= (full_loops*last);
            while(x[i] > sum[n-1]) {
                full_loops += 1;
                x[i] -= last;
            }
        }
        vector <ll>::iterator it;
        it = lower_bound(v.begin(), v.end(), x[i]);
        ll pos = (it - v.begin());
        cout << n*full_loops + pos << " ";
    }
    cout << "\n";
}
    return 0;
}