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

const int max_n = 1111, inf = 1111111111;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int p[max_n * max_n], sz[max_n * max_n];

void fill_p(int n) {
    for (int i = 0; i <= n; ++i) {
        p[i] = i;
        sz[i] = 0;
    }
}

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}
void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (sz[v1] > sz[v2]) {
        swap(v1, v2);
    }
    p[v1] = v2;
    sz[v2] += sz[v1];
}

int n, m, a[max_n][max_n], used[max_n][max_n];
vector<pair<int, pair<int, int> > > v;
multiset<int> all;
long long k;

bool is_in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void proc(int x, int y) {
    int q = x * m + y;
    sz[q] = 1;
    all.insert(1);
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (is_in(nx, ny)) {
            int w = nx * m + ny;
            q = find_set(q);
            w = find_set(w);
            if (sz[w]) {
                if (q != w) {
                    all.erase(all.find(sz[q]));
                    all.erase(all.find(sz[w]));
                    union_set(q, w);
                    w = find_set(w);
                    all.insert(sz[w]);
                }
            }
        }
    }
}

void dfs(int x, int y, int mn) {
    k -= mn;
    if (k < 0) {
        return;
    }
    used[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], b = y + dy[i];
        if (is_in(xx, b) && used[xx][b] == 0 && a[xx][b] >= mn) {
            dfs(xx, b, mn);
        }
    }
}

void write(int x) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = x;
            if (used[i][j] == 0) {
                a[i][j] = 0;
            }
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%I64d", &n, &m, &k);
    fill_p(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            v.push_back(make_pair(a[i][j], make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        //cout << i << " : " << v[i].second.first << " " << v[i].second.second << endl;
        proc(v[i].second.first, v[i].second.second);
        int mx = *all.rbegin();
        if (k % v[i].first == 0 && k / v[i].first <= mx) {
            printf("YES\n");
            dfs(v[i].second.first, v[i].second.second, v[i].first);
            write(v[i].first);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}