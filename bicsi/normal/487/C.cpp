#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    if (n <= 10) {
        vector<int> perm;
        for (int i = 0; i < n; ++i)
            perm.push_back(i);

        do {
            int now = 1;
            set<int> s;
            for (int i = 0; i < (int)perm.size(); ++i) {
                now = now * perm[i] % n;
                s.insert(now);
            }
            if (s.size() == n) {
                cout << "YES\n";
                for (auto& x : perm) {
                    cout << (x == 0 ? n : x) << " ";    
                }
                cout << endl;
                return 0;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        cout << "NO\n";
    } else {
        for (int d = 2; d < n; ++d) {
            if (n % d == 0) {
                cout << "NO\n";
                return 0;
            }
        }

        auto inv = [&](int x) {
            int e = n - 2, r = 1;
            while (e) {
                if (e % 2) r = 1LL * r * x % n;
                x = 1LL * x * x % n;
                e /= 2;
            }
            return r;
        };

        cout << "YES\n";
        cout << 1 << " ";
        for (int i = 2; i < n; ++i) {
            cout << 1LL * inv(i - 1) * i % n << ' ';
        }
        cout << n << endl;
    }
    return 0;
}