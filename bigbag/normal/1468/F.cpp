/**
 *  created: 25/12/2020, 13:57:30
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        map<pair<int, int>, int> q;
        while (n--) {
            int a, b, x, y;
            scanf("%d%d%d%d", &a, &b, &x, &y);
            x -= a;
            y -= b;
            int g = __gcd(abs(x), abs(y));
            x /= g;
            y /= g;
            ++q[{x, y}];
        }
        long long ans = 0;
        for (auto p : q) {
            int c = 0;
            auto it = q.find({-p.first.first, -p.first.second});
            if (it != q.end()) {
                c = it->second;
            }
            ans += 1LL * p.second * c;
        }
        assert(ans % 2 == 0);
        ans /= 2;
        cout << ans << "\n";
    }
    return 0;
}