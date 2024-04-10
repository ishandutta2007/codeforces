#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int arr[n];
    forn(i, 0, n) cin >> arr[i];
    if(arr[0]==1) {
        cout << n + 1 << " ";
        forn(i, 1, n+1) cout << i << " ";
        cout << endl;
        return;
    }
    if(arr[n-1]==0) {
        forn(i, 1, n+1) cout << i << " ";
        cout << n+1 << " ";
        cout << endl;
        return;
    }
    forn(i, 0, n-1) {
        if(arr[i] == 0 && arr[i+1] == 1) {
            forn(j, 1, i + 2) cout << j << " ";
            cout << n+1 << " ";
            forn(j, i+2, n+1) cout << j << " ";
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t; while(t--)
    {solve();}
    return 0;
}