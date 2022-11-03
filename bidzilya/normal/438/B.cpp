#include <cstdio>
#include <cstdlib>

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

int n, m;
vector<vector<int> > g;
int a[max_n];
pair<int, int> b[max_n];

int parent_dsu[max_n];
int rank_dsu[max_n];
int sz_dsu[max_n];

int find_dsu(int v)
{
    if (parent_dsu[v] != v) parent_dsu[v] = find_dsu(parent_dsu[v]);
    return parent_dsu[v];
}

void init_dsu()
{
    for (int i = 0; i < n; ++i) {
        parent_dsu[i] = i;
        rank_dsu[i] = 0;
        sz_dsu[i] = 1;
    }
}

pair<int, int> union_dsu(int v1, int v2)
{
    v1 = find_dsu(v1);
    v2 = find_dsu(v2);
    if (v1 == v2) return make_pair(0, 0);
    if (rank_dsu[v2] > rank_dsu[v1]) swap(v1, v2);
    parent_dsu[v2] = v1;
    if (rank_dsu[v1] == rank_dsu[v2]) ++rank_dsu[v1];
    pair<int, int> res = make_pair(sz_dsu[v1], sz_dsu[v2]);
    sz_dsu[v1] += sz_dsu[v2];
    return res;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
        
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    g.resize(n);
    for (int i = 0; i < m; ++i) { 
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i = 0; i < n; ++i) {
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b, b + n);
    ll ans = 0;
    init_dsu();
    for (int i = n - 1; i >= 0; --i) {
        int v = b[i].second;
        for (int j = 0; j < (int) g[v].size(); ++j) {
            int u = g[v][j];
            if (a[u] >= a[v]) {
                pair<int, int> sz = union_dsu(v, u);
                ans += 1LL * sz.first * sz.second * a[v];
            }
        }
    }
    double ans_d = 2.0 * ans / n / (n - 1);
    printf("%.15lf\n", ans_d);

    return 0;
}