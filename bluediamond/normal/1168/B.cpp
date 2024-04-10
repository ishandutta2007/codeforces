#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(vector <int> a) {
        int n = (int) a.size();
        for (int i = 0; i < n; i++) {
                for (int ln = 1; i + 2 * ln < n; ln++) {
                        if (a[i] == a[i + ln] && a[i + ln] == a[i + 2 * ln]) {
                                return 1;
                        }
                }
        }
        return 0;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        string s;
        cin >> s;
        int n = (int) s.size();

        vector <int> v(n);
        for (int i = 0; i < n; i++) {
                v[i] = (s[i] - '0');
        }

        /// good = total - bad
        /// good = n * (n + 1) / 2 - bad

        ll bad = 0LL;

        for (int i = 0; i < n; i++) {
                for (int ln = 1; ln <= 8 && i + ln - 1 < n; ln++) {
                        vector <int> b;
                        for (int j = i; j <= i + ln - 1; j++) {
                                b.push_back(v[j]);
                        }
                        bad += !(check(b));
                }
        }

        ll total = n * (ll) (n + 1) / 2;
        ll good = total - bad;

        cout << good << "\n";


        return 0;
}