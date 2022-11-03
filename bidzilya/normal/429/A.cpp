#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
 
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

int n;
vector<vector<int> > g;
int a[max_n];
int b[max_n];

vector<int> ans;

void calc_ans(int v, int c1, int c2, int p)
{
    a[v] = (a[v] + c2) & 1;
    if (a[v] != b[v]) {
        ++c2;
        ans.push_back(v);
    } 
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != p) {
           calc_ans(u, c2, c1, v);
        }
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    calc_ans(0, 0, 0, -1);
    printf("%d\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); ++i)
        printf("%d\n", ans[i] + 1);

    return 0;
}