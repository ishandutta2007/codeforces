#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], b[max_n];
map<int, vector<int>> m;
set<int> all;
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        m[a[i]].push_back(b[i]);
        all.insert(a[i]);
    }
    multiset<int> q;
    long long sum = 0;
    for (int x = 0; ; ) {
        auto it = m.find(x);
        if (it != m.end()) {
            for (int t : it->second) {
                q.insert(t);
                sum += t;
            }
        }
        if (!q.empty()) {
            sum -= *q.rbegin();
            q.erase(--q.end());
        }
        ans += sum;
        if (q.empty()) {
            auto it = all.upper_bound(x);
            if (it == all.end()) {
                break;
            }
            x = *it;
        } else {
            ++x;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}