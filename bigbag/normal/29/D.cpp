#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333, inf = 111111111;

int n, u[max_n], v[max_n], p[max_n], l[max_n], used[max_n], used1[max_n][max_n];
map <int, int> s;
vector <int> g[max_n], pyt, ans;

bool dfs(int v, int x) {
    if (v == x) {
        pyt.push_back(v);
        return true;
    }
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            if (dfs(g[v][i], x)) {
                pyt.push_back(v);
                return true;
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u[i] >> v[i];
        p[v[i]] = u[i];
        p[u[i]] = v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        s[u[i]]++;
        s[v[i]]++;
    }
    int m = 0;
    for (int i = 2; i <= n; ++i) {
        if (s[i] < 2) {
            ++m;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> l[i];
    }
    int start = 1;
    ans.push_back(1);
    for (int i = 0; i < m; ++i) {
        pyt.clear();
        for (int j = 1; j <= n; ++j) {
            used[j] = 0;
        }
        dfs(start, l[i]);
        /*if (dfs(start, l[i]) == false) {
            cout << start << ' ' << l[i] << "!" << endl;
        }*/
        for (int j = pyt.size() - 2; j >= 0; --j) {
            ans.push_back(pyt[j]);
            if (j != pyt.size() - 1) {
                used1[pyt[j + 1]][pyt[j]]++;
                used1[pyt[j]][pyt[j + 1]]++;
            }
        }
        /*used1[l[i]][p[l[i]]]++;
        used1[p[l[i]]][l[i]]++;
        start = p[l[i]];*/
        start = l[i];
    }
    if (start != 1) {
        pyt.clear();
        for (int j = 1; j <= n; ++j) {
            used[j] = 0;
        }
        dfs(start, 1);
        for (int j = pyt.size() - 2; j >= 0; --j) {
            ans.push_back(pyt[j]);
            if (j != pyt.size() - 1) {
                used1[pyt[j + 1]][pyt[j]]++;
                used1[pyt[j]][pyt[j + 1]]++;
            }
        }
    } else {
        //ans.push_back(1);
    }
    for (int i = 1; i < n; ++i) {
        if (used1[u[i]][v[i]] != 2 || used1[v[i]][u[i]] != 2) {
            cout << "-1";
            return 0;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}