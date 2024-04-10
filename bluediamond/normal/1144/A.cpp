#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int t;
        cin >> t;
        while (t--) {
                string s;
                cin >> s;
                sort(s.begin(), s.end());
                bool ok = 1;
                int last = -1;
                for (auto &ch : s) {
                        int x = ch - 'a';
                        if (last != -1 && last + 1 != x) {
                                ok = 0;
                        }
                        last = x;
                }
                if (ok) {
                        cout << "Yes\n";
                } else {
                        cout << "No\n";
                }
        }
        return 0;
}
/**

**/