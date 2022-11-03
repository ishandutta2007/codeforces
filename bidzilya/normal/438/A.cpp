#include <cstdio>
#include <cstdlib>

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 1e3 + 10;

int n, m;
int v[max_n], c[max_n], used[max_n];
vector<vector<int> > g;

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
        
    scanf("%d%d", &n, &m);
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        c[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
        ++c[v1];
        ++c[v2];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) 
        ans += v[i] * c[i];
    for (int i = 0; i < n; ++i)
        used[i] = 0;
    for (int i = 0; i < n; ++i) {
        int mx = -1;
        for (int j = 0; j < n; ++j) 
            if (!used[j] && (mx == -1 || v[j] > v[mx])) 
                mx = j;
        used[mx] = 1;
        ans -= c[mx] * v[mx];
        for (int j = 0; j < (int) g[mx].size(); ++j) {
            int v = g[mx][j];
            --c[v];
        }
    }
    printf("%d\n", ans);
    

    
    return 0;
}