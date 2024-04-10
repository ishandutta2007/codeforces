#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

const int max_n = 100111, inf = 1000111222;

int c[max_n];
int x[max_n];
int n;
ll k, a;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", x + i);
    }
    cin >> a;
    for (int i = 0; i < n; ++i) {
        scanf("%d", c + i);
    }
    multiset<int> ms;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ms.insert(c[i]);
        while (k < x[i]) {
            if (ms.empty()) {
                cout << -1 << endl;
                return 0;
            }
            ans += *ms.begin();
            ms.erase(ms.begin());
            k += a;
        }
    }
    cout << ans << endl;
    return 0;
}