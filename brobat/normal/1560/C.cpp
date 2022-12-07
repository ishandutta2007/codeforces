#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int k;
    cin >> k;
    int n = ceil(sqrt(k));
    int diff = n*n - k;
    if(diff >= n) {
        cout << 2*(n-1) - diff + 1 << " " << n << endl;
    }
    else {
        cout << n << " " << diff + 1 << endl;
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