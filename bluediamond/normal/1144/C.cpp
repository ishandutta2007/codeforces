#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin >> n;
        vector <int> v(n);
        vector <bool> used(n, 0);
        for (int i = 0; i < n; i++) {
                cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector <int> a;
        vector <int> b;
        int last = -1;
        for (int i = 0; i < n; i++) {
                if (used[i] == 0 && v[i] != last) {
                        used[i] = 1;
                        last = v[i];
                        a.push_back(v[i]);
                }
        }
        last = -1;
        for (int i = 0; i < n; i++) {
                if (used[i] == 0 && v[i] != last) {
                        used[i] = 1;
                        last = v[i];
                        b.push_back(v[i]);
                }
        }
        for (int i = 0; i < n; i++) {
                if (used[i] == 0) {
                        cout << "NO\n";
                        return 0;
                }
        }
        reverse(b.begin(), b.end());
        cout << "YES\n";
        cout << a.size() << "\n";
        for (auto &x : a) {
                cout << x << " ";
        }
        cout << "\n";
        cout << b.size() << "\n";
        for (auto &x : b) {
                cout << x << " ";
        }
        cout << "\n";
        return 0;
}
/**
**/