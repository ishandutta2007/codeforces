//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int n;
// int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = __gcd(n, 100-n);
        cout << 100/ans << endl;
    }
    return 0;
}