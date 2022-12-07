#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    ll n;
    cin >> n;
    ll arr[n];
    forn(i, n) cin >> arr[i];
    vector <int> v;
    ll temp = arr[0];
    v.push_back(0);
    forn(i, n-1) {
        ll temp2 = (~arr[i+1]) & temp;
        v.push_back(temp2);
        temp = arr[i+1]^temp2;
    }
    for(auto i: v) cout << i << " ";
    cout << endl;
}
    return 0;
}