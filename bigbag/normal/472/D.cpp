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

const int max_n = 2022, inf = 1111111111;

void write(string s) {
    cout << s << endl;
    exit(0);
}

struct state {
    int u, v, d;
    state() {
    }
    state(int u, int v, int d) : u(u), v(v), d(d) {
    }
    bool operator < (const state &s) const {
        return d < s.d;
    }
};

int n, a[max_n][max_n], p[max_n], dist[max_n][max_n];
vector<state> v;
vector<int> g[max_n], d[max_n], cp;

int find_set(int x) {
    if (x == p[x]) {
        return x;
    }
    return p[x] = find_set(p[x]);
}

void union_set(int x, int y) {
    p[x] = y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        if (a[i][i] != 0) {
            write("NO");
        }
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] != a[j][i] || a[i][j] == 0) {
                write("NO");
            }
            v.push_back(state(i, j, a[i][j]));
        }
    }
    sort(v.begin(), v.end());
    for (int k = 0; k < v.size(); ++k) {
        int v1 = v[k].u, v2 = v[k].v;
        int num1 = find_set(v1), num2 = find_set(v2);
        if (num1 != num2) {
            union_set(num1, num2);
            dist[v1][v2] = v[k].d;
            dist[v2][v1] = v[k].d;
            for (int i = 0; i < g[v1].size(); ++i) {
                for (int j = 0; j < g[v2].size(); ++j) {
                    dist[g[v1][i]][g[v2][j]] = d[v1][i] + v[k].d + d[v2][j];
                    dist[g[v2][j]][g[v1][i]] = d[v1][i] + v[k].d + d[v2][j];
                }
            }
            int sz1 = g[v1].size(), sz2 = g[v2].size();
            for (int i = 0; i < sz2; ++i) {
                g[v1].push_back(g[v2][i]);
                d[v1].push_back(v[k].d + d[v2][i]);
                //g[g[v2][i]].push_back(v1);
                //d[g[v2][i]].push_back(v[k].d + d[v2][i]);
                dist[v1][g[v2][i]] = v[k].d + d[v2][i];
                dist[g[v2][i]][v1] = v[k].d + d[v2][i];
            }
            for (int i = 0; i < sz1; ++i) {
                g[v2].push_back(g[v1][i]);
                d[v2].push_back(v[k].d + d[v1][i]);
                //g[g[v1][i]].push_back(v2);
                //d[g[v1][i]].push_back(v[k].d + d[v1][i]);
                dist[v2][g[v1][i]] = v[k].d + d[v1][i];
                dist[g[v1][i]][v2] = v[k].d + d[v1][i];
            }
            g[v1].push_back(v2);
            d[v1].push_back(v[k].d);
            g[v2].push_back(v1);
            d[v2].push_back(v[k].d);
            //cout << "@" << v1 << " " << v2 << endl;
            for (int i = 0; i < sz1; ++i) {
                for (int j = 0; j < sz2; ++j) {
                    //cout << i << " " << j << endl;
                    //char c;
                    //cin >> c;
                    int uu = g[v1][i], vv = g[v2][j];
                    g[uu].push_back(vv);
                    g[vv].push_back(uu);
                    d[uu].push_back(dist[uu][vv]);
                    d[vv].push_back(dist[uu][vv]);
                }
            }
            for (int i = 0; i < sz2; ++i) {
                g[g[v2][i]].push_back(v1);
                d[g[v2][i]].push_back(v[k].d + d[v2][i]);
            }
            for (int i = 0; i < sz1; ++i) {
                g[g[v1][i]].push_back(v2);
                d[g[v1][i]].push_back(v[k].d + d[v1][i]);
            }
            //cout << v1 << " " << v2 << endl;
        } else {
            //cout << "@" << v1 << " " << v2 << " " << dist[v1][v2] << endl;
            if (dist[v1][v2] != v[k].d) {
                write("NO");
            }
        }
    }
    write("YES");
    return 0;
}