#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
  
typedef long long ll;

const int max_n = 1e5;
const int max_a = 1e5;
const int max_s_over_e = 300;

int a[max_n + 1];
int n;
int b[max_n + 1];
int m;
int s;
int e;

int ans[max_n + 1][max_s_over_e + 1];

int hd[max_a + 1];
int d[max_n];
int nx[max_n];
int sz;

int ptr[max_a + 1];

void init_list()
{
    for (int i = 1; i <= max_a; ++i) hd[i] = -1;
    sz = 0;
}

void add_to_list(int v, int x)
{
    d[sz] = x;
    nx[sz] = hd[v];
    hd[v] = sz;
    ++sz;
}

void init_ptr()
{
    for (int i = 1; i <= max_a; ++i) ptr[i] = hd[i];
}

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= m; ++i) scanf("%d", b + i);
    
    init_list();
    for (int i = m; i >= 1; --i)
        add_to_list(b[i], i);
        
    int max_steps = s / e;

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= max_steps; ++j)
            ans[i][j] = -1;
    
    for (int i = 0; i <= n; ++i)
        ans[i][0] = 0;
    
    for (int j = 1; j <= max_steps; ++j) {
        init_ptr();
        for (int i = n - 1; i >= 0; --i)
            if (ans[i][j - 1] != -1) {
                int val = a[i + 1];
                int k = ans[i][j - 1] + 1;
                while (true) {
                    if (ptr[val] == -1) break;
                    if (d[ptr[val]] < k) {
                        ptr[val] = nx[ptr[val]];
                    } else {
                        break;
                    }
                }
                if (ptr[val] == -1) continue;
                int t = d[ptr[val]];
                if (ans[i + 1][j] == -1 || t < ans[i + 1][j]) {
                    ans[i + 1][j] = t;
                }
            }
        for (int i = 0; i + 1 <= n; ++i)
            if (ans[i][j] != -1) {
                if (ans[i + 1][j] == -1 || ans[i][j] < ans[i + 1][j]) {
                    ans[i + 1][j] = ans[i][j];
                }
            }
    }
    
    int res = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= max_steps; ++j) 
            if (ans[i][j] != -1 && e * j + i + ans[i][j] <= s) 
                res = max(res, j);
    
    printf("%d\n", res);

    return 0;
}