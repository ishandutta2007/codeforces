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

const int max_n = 55, inf = 1111111111;

int n, a[max_n], used[max_n];
long long k, dp[max_n];
vector<int> v, v2;
vector<vector<int> > q;

void dfs(int V) {
    used[V] = 1;
    v.push_back(V);
    if (used[a[V]]) {
        return;
    }
    dfs(a[V]);
}

bool check() {
    q.clear();
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            v.clear();
            v2.clear();
            dfs(i);
            int mx = -1, poz;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i] > mx) {
                    mx = v[i];
                    poz = i;
                }
            }
            for (int i = poz; i < v.size(); ++i) {
                //cout << v[i] << " ";
                v2.push_back(v[i]);
            }
            for (int i = 0; i < poz; ++i) {
                //cout << v[i] << " ";
                v2.push_back(v[i]);
            }
            //cout << ", ";
            q.push_back(v2);
        }
    }
    v.clear();
    sort(q.begin(), q.end());
    for (int i = 0; i < q.size(); ++i) {
        for (int j = 0; j < q[i].size(); ++j) {
            v.push_back(q[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        //cout << v[i] << " ";
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] != a[i]) {
            return false;
        }
    }
    return true;
}

void trivial() {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    int cnt = 0;
    do {
        if (check()) {
            ++cnt;
            if (cnt == k) {
                for (int i = 0; i < n; ++i) {
                    cout << a[i] + 1 << " ";
                }
                cout << endl;
                return;
            }
        }
    } while (next_permutation(a, a + n));
    cout << cnt << endl;
}

void solve() {
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for (int i = 0; i < n;) {
        if (dp[n - i - 1] >= k) {
            cout << i + 1 << " ";
            ++i;
            continue;
        }
        k -= dp[n - i - 1];
        cout << i + 2 << " " << i + 1 << " ";
        i += 2;
    }
    cout << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    solve();
    return 0;
}