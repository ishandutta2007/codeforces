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
    ll s = 0;
    forn(i, n) s += arr[i];
    s %= n;
    cout << s*(n-s) << "\n";
}
    return 0;
}