#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

long long gcd(long long a, long long b) {
    a = abs(a);
    b = abs(b);
    while (a != 0 && b != 0) {
        long long k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

long long n, m, a[max_n], b[max_n], ans[max_n], mins[max_n];
vector<long long> g[max_n], Gcd[max_n], Lcm[max_n];

bool dfs(int v) {
    //cout << v << endl;
    for (int i = 0; i < g[v].size(); ++i) {
        if (ans[g[v][i]] == 0) {
            if (Gcd[v][i] * Lcm[v][i] % ans[v] != 0) {
                ans[v] = 0;
                return false;
            }
            ans[g[v][i]] = Gcd[v][i] * Lcm[v][i] / ans[v];
            if (!dfs(g[v][i])) {
                ans[v] = 0;
                return false;
            }
        } else {
            //cout << "   " << v << ' ' << g[v][i] << endl;
            if (Gcd[v][i] != gcd(ans[v], ans[g[v][i]]) || Lcm[v][i] != lcm(ans[v], ans[g[v][i]])) {
                ans[v] = 0;
                return false;
            }
        }
    }
    //cout << v << ' ' << ans[v] << endl;
    return true;
}

void NUL(int v) {
    ans[v] = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (ans[g[v][i]] != 0) {
            NUL(g[v][i]);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        long long u, v, gc, lc;
        cin >> u >> v >> gc >> lc;
        g[u].push_back(v);
        Gcd[u].push_back(gc);
        Lcm[u].push_back(lc);
        g[v].push_back(u);
        Gcd[v].push_back(gc);
        Lcm[v].push_back(lc);
        if (a[u] == 0 && b[u] == 0) {
            a[u] = gc;
            b[u] = lc;
        } else {
            a[u] = lcm(a[u], gc);
            b[u] = gcd(b[u], lc);
        }
        if (a[v] == 0 && b[v] == 0) {
            a[v] = gc;
            b[v] = lc;
        } else {
            a[v] = lcm(a[v], gc);
            b[v] = gcd(b[v], lc);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] != 0 && b[i] != 0) {
            for (int j = a[i]; j * j <= b[i]; j += a[i]) {
                if (b[i] % j == 0) {
                    mins[i] = j;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        //cout << i << "  " << a[i] << ' ' << b[i] << endl;
        if (a[i] == 0 && b[i] == 0) {
            ans[i] = 1;
        } else if (ans[i] == 0) {
            for (int j = 1; j * j <= b[i]; j += 1) {
                if (b[i] % j == 0) {
                    if (j % a[i] == 0) {
                        ans[i] = j;
                        if (dfs(i)) {
                            break;
                        }
                        NUL(i);
                    }
                    if ((b[i] / j) % a[i] == 0) {
                        ans[i] = b[i] / j;
                        if (dfs(i)) {
                            break;
                        }
                        NUL(i);
                    }
                }
            }
            if (ans[i] == 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}