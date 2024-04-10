#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    multiset <int> s;
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        int price;
        cin >> price;
        if (i >= 2 && price - *s.begin() > 0) {
            ans += price - *s.begin();
            s.erase(s.begin());
            s.insert(price);
        }
        s.insert(price);
    }
    cout << ans << "\n";

    return 0;
}