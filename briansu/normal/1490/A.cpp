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
        int n;
        cin >> n;
        int last, ans = 0;
        cin >> last;
        for (int i = 2; i <= n; i++) {
            int now;
            cin >> now;
            int a = min(now, last), b = max(now, last);
            while (a * 2 < b)
                ans++, a *= 2;
            last = now;
        }
        cout << ans << "\n";
    }
            
}