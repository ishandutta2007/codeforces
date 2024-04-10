#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

int n, m, z[max_n];
vector<int> g[max_n];

void get_z_function(int len) {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < len; ++i) {
        z[i] = 0;
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < len && g[i + z[i]] == g[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

set<pair<int, int>> q1, q2;

bool check(int len) {
    for (const pair<int, int> &p : q1) {
        int a = (p.first + len) % n;
        int b = (p.second + len) % n;
        if (a > b) {
            swap(a, b);
        }
        q2.insert({a, b});
    }
    return q1 == q2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            swap(a, b);
        }
        --a;
        --b;
        q1.insert({a, b});
        int l1 = b - a;
        int l2 = n - l1;
        if (l1 < l2) {
            g[a].push_back(l1);
        } else {
            g[b].push_back(l2);
        }
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    for (int i = n; i < 2 * n; ++i) {
        g[i] = g[i - n];
    }
    get_z_function(2 * n);
    for (int i = 1; i < n; ++i) {
        if (z[i] >= n) {
            puts("Yes");
            return 0;
        }
    }
    if (n % 2 == 0 && check(n / 2)) {
        puts("Yes");
        return 0;
    }
    puts("No");
    return 0;
}