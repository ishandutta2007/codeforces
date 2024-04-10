#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

const int max_n = 1e3 + 10;

int n;
int c[max_n], p[max_n];
int k;
int r[max_n];

int gu[max_n];
int u[max_n];
int mr[max_n];

bool try_kuhn(int v)
{
    if (u[v]) return false;
    
    u[v] = true;
    for (int i = 0; i < k; ++i)
        if (r[i] >= c[v]) {
            if (mr[i] == -1 || try_kuhn(mr[i])) {
                mr[i] = v;
                return true;
            }
        }
    return false;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", c + i, p + i);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
        scanf("%d", r + i);

    for (int i = 0; i < k; ++i) mr[i] = -1;
    for (int i = 0; i < n; ++i) gu[i] = 0;
    for (int i = 0; i < n; ++i) {
        int id = -1;
        for (int j = 0; j < n; ++j)
            if (!gu[j] && (id == -1 || p[j] > p[id]))
                id = j;
        gu[id] = true;
        for (int j = 0; j < n; ++j) u[j] = 0;
        try_kuhn(id);
    }
    
    int c = 0, ans = 0;
    vector<pair<int, int> > vans;
    for (int i = 0; i < k; ++i) 
        if (mr[i] != -1) {
            ++c;
            ans += p[mr[i]];
            vans.push_back(make_pair(mr[i] + 1, i + 1));
        }
        
    sort(vans.begin(), vans.end());
    
    printf("%d %d\n", c, ans);
    for (int i = 0; i < c; ++i)
        printf("%d %d\n", vans[i].first, vans[i].second);

    return 0;
}