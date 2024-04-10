#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int N = 1000001;
long long a[N];
int n;
vector<int>g[100];
bool bz[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        long long x = a[i];
        int y = 0;
        while ((x & 1) == 0) x >>= 1, y++;
        g[y].push_back(i);
    }
    int x = 0;
    for (int i = 0; i < 100; i ++)
        if (g[i].size() > g[x].size())
            x = i;
    for (auto u:g[x])
        bz[u] = 1;
    printf("%d\n", n - g[x].size());
    for (int i = 1; i <= n ; i++)
        if (!bz[i])printf("%lld ", a[i]);
    return 0;
}