#include <bits/stdc++.h>

using namespace std;

const int max_n = 1, inf = 1111111111;

int n;
long long ans;
map<int, int> q[2];
map<pair<int, int>, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++q[0][x];
        ++q[1][y];
        ++m[make_pair(x, y)];
    }
    for (int i = 0; i < 2; ++i) {
        for (map<int, int>::iterator it = q[i].begin(); it != q[i].end(); ++it) {
            pair<int, int> p = *it;
            ans += (1LL * p.second * (p.second - 1)) / 2;
        }
    }
    for (map<pair<int, int>, int>::iterator it = m.begin(); it != m.end(); ++it) {
        pair<pair<int, int>, int> p = *it;
        ans -= (1LL * p.second * (p.second - 1)) / 2;
    }
    printf("%I64d\n", ans);
    return 0;
}