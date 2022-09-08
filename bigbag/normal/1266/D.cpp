#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, m;
long long bal[max_n];
vector<int> ansu, ansv;
vector<long long> ansx;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        --u;
        --v;
        bal[u] -= x;
        bal[v] += x;
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (bal[i] < 0) {
            v.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        while (bal[i] > 0) {
            int to = v.back();
            long long x = min(bal[i], -bal[to]);
            bal[i] -= x;
            bal[to] += x;
            ansu.push_back(i);
            ansv.push_back(to);
            ansx.push_back(x);
            if (bal[to] == 0) {
                v.pop_back();
            }
        }
    }
    printf("%d\n", ansu.size());
    for (int i = 0; i < ansu.size(); ++i) {
        printf("%d %d %I64d\n", ansv[i] + 1, ansu[i] + 1, ansx[i]);
    }
    return 0;
}