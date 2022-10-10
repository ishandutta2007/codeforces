#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back


int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    long i, f, g;

    long n; cin >> n;

    if (n <= 2)  return cout << -1, 0;
    if (n & 1) {
        long x = (n + 1) / 2;
        long y = (n - 1) / 2;
        cout << (2 * x * y) << ' ' << (x * x + y * y);
        return 0;
    } else {
        long x = 1;
        long y = n / 2;
        cout << (y * y - x * x) << ' ' << (y * y + x * x);
    }

    return 0;
}