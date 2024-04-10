#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, x[max_n], y[max_n];
multiset<pair<int, int>> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    x[n] = x[0];
    y[n] = y[0];
    for (int i = 1; i <= n; ++i) {
        q.insert({x[i] - x[i - 1], y[i] - y[i - 1]});
    }
    while (!q.empty()) {
        pair<int, int> p = *q.begin();
        q.erase(q.find(p));
        p.first *= -1;
        p.second *= -1;
        auto it = q.find(p);
        if (it == q.end()) {
            puts("NO");
            return 0;
        }
        q.erase(it);
    }
    puts("YES");
    return 0;
}