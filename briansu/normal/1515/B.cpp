#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, c = 0;
        cin >> n;
        while (n % 2 == 0)
            n /= 2, c++;
        int p = sqrt(n + 0.5);
        if (c > 0 && p * p == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}