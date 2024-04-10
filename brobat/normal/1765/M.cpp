#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> f;
        for(int i = 1; i <= (sqrt(n)); i++) {
            if(n % i == 0) {
                f.push_back(i);
                if(i != n / i) {
                    f.push_back(n/i);
                }
            }
        }
        int ans = 0;
        for(auto g : f) {
            if(g == n) continue;
            ans = max(ans, g);
        }
        cout << n - ans << ' ' << ans << '\n';
    }
}