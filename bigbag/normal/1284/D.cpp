#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, l1[max_n], r1[max_n], l2[max_n], r2[max_n];

void solve() {
    multiset<int> mn, mx;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.push_back({l1[i], -1 - i});
        v.push_back({r1[i], i});
    }
    sort(v.begin(), v.end());
    for (const auto &p : v) {
        if (p.second < 0) {
            int id = -p.second - 1;
            //cout << "+ " << id << endl;
            if (!mn.empty()) {
                //cout << "$" << *mn.begin() << " " << l2[id] << endl;
                if (*mn.begin() < l2[id] || *mx.rbegin() > r2[id]) {
                    puts("NO");
                    exit(0);
                }
            }
            mn.insert(r2[id]);
            mx.insert(l2[id]);
        } else {
            int id = p.second;
            //cout << "- " << id << endl;
            mn.erase(mn.find(r2[id]));
            mx.erase(mx.find(l2[id]));
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &l1[i], &r1[i], &l2[i], &r2[i]);
    }
    for (int it = 0; it < 2; ++it) {
        solve();
        for (int i = 0; i < n; ++i) {
            swap(l1[i], l2[i]);
            swap(r1[i], r2[i]);
        }
    }
    puts("YES");
    return 0;
}