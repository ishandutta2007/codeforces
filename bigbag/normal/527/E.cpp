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

const int max_n = 500005, inf = 1111111111;

int n, m, u[max_n], v[max_n], f[max_n];
vector<int> g[max_n], ans;

void add_edges() {
    vector<int> q;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() % 2 == 1) {
            q.push_back(i);
        }
    }
    for (int i = 0; i + 1 < q.size(); i += 2) {
        u[m] = q[i];
        v[m] = q[i + 1];
        g[u[m]].push_back(m);
        g[v[m]].push_back(m);
        ++m;
    }
    if (m % 2 == 1) {
        u[m] = rand() % n + 1;
        v[m] = u[m];
        g[u[m]].push_back(m);
        ++m;
    }
}

void find_path(int vv) {
    stack<int> st;
    st.push(vv);
    while (!st.empty()) {
        vv = st.top();
        int ff = 0;
        while (g[vv].size()) {
            int to = g[vv].back();
            g[vv].pop_back();
            if (f[to] == 0) {
                f[to] = 1;
                ff = 1;
                if (vv == v[to]) {
                    swap(u[to], v[to]);
                }
                st.push(v[to]);
                break;
            }
        }
        if (ff == 0) {
            ans.push_back(vv);
            st.pop();
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        g[u[i]].push_back(i);
        g[v[i]].push_back(i);
    }
    add_edges();
    find_path(1);
    printf("%d\n", ans.size() - 1);
    for (int i = 0; i + 1 < ans.size(); ++i) {
        if (i % 2 == 0) {
            printf("%d %d\n", ans[i], ans[i + 1]);
        } else {
            printf("%d %d\n", ans[i + 1], ans[i]);
        }
    }
    return 0;
}