#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = (int) 1e5 + 7;
vector<int> bad[N];

void solve(int n, int m, vector<int> a, vector<int> b, vector<int> c) {
        for (int i = 1; i <= n; i++)
                bad[i].clear();
        for (int i = 0; i < n; i++)
                if (a[i] != b[i])
                        bad[b[i]].push_back(i);
        vector<int> ret;
        for (int i = 0; i < m - 1; i++) {
                int x = c[i];
                if (!bad[x].empty()) {
                        int i = bad[x].back();
                        bad[x].pop_back();
                        assert(b[i] == x && a[i] != x);
                        a[i] = x;
                        ret.push_back(i);
                        continue;
                }
                ret.push_back(-1);
        }
        vector<int> errors;
        for (int i = 0; i < n; i++)
                if (a[i] != b[i])
                        errors.push_back(i);
        if ((int) errors.size() >= 2) {
                cout << "NO\n";
                return;
        }
        int x = c.back();
        if (errors.empty()) {
                for (int i = 0; i < n; i++) {
                        if (a[i] == x && b[i] == x) {
                                errors.push_back(i);
                                break;
                        }
                }
                if (errors.empty()) {
                        cout << "NO\n";
                        return;
                }
        }
        assert((int) errors.size() == 1);
        if (b[errors[0]] != x) {
                cout << "NO\n";
                return;
        }
        ret.push_back(-1);
        cout << "YES\n";
        for (auto &x : ret) {
                if (x == -1)
                        x = errors[0];
                cout << x + 1 << " ";
        }
        cout << "\n";
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                int n, m;
                cin >> n >> m;
                vector<int> a(n), b(n), c(m);
                for (auto &x : a)
                        cin >> x;
                for (auto &x : b)
                        cin >> x;
                for (auto &x : c)
                        cin >> x;
                solve(n, m, a, b, c);

        }

}
/**

**/