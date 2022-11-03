#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int> > g;
vector<int> top;
vector<int> used;

void top_sort(int v)
{
    used[v] = 1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (!used[u])
            top_sort(u);
    }
    top.push_back(v);
}

int main()
{
  //  freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        g[v1].push_back(v2);
    }
    
    used.assign(n, 0);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            top_sort(i);
    for (int i = 0; i < n; ++i)
        printf("%d ", top[i] + 1);
    printf("\n");
    return 0;
}