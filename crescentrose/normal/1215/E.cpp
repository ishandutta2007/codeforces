#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#define log lg
#include <unordered_map>
using namespace std;
const int N = 1e6;
int n;
vector<int>g[21];
int log[1<<20];
long long f[1<<20], a[20][20];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < 20; i ++)
        log[1<<i] = i;
    for (int i = 1; i <= n ; i ++){
        int x;
        scanf("%d", &x);
        g[x - 1].push_back(i);
    }
    for (int i = 0; i < 20; i ++)
        for (int j = 0; j < 20; j ++)
            if (i != j && g[i].size() && g[j].size()) {
                int pos2 = 0;
                for (int pos1 = 0; pos1 < g[i].size(); pos1 ++){
                    while (pos2 < g[j].size() - 1 && g[j][pos2 + 1] < g[i][pos1]) pos2 ++;
                    if (g[i][pos1] > g[j][pos2])
                        a[i][j] += pos2 + 1;
                }
            }
    for (int i = 1; i < (1 << 20); i ++)
        if ((i&-i) != i)
            f[i] = 1e18;
    for (int i = 1;i < (1 << 20); i ++){
        int x = i ^ ((1 << 20) - 1);
        while (x) {
            int xx = x & -x;
            int y = i;
            long long v = f[i];
            while (y) {
                v += a[log[y & -y]][log[xx]];
                y -= y & -y;
            }
            f[xx + i] = min(f[xx + i], v);
            x -= xx;
        }
    }
    cout<<f[(1<<20) - 1];
    return 0;
}