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
const int N = 1e5 + 1;
long long a[N];
pair<long long, int> f[N][50];
int tot[N];
int n;
vector<int> g[N];
long long ans;
const int mod = 1e9 + 7;
void dfs(int x, int fa, int dep) {
    for (int i = 0; i < tot[dep]; i ++)
        f[dep][i].first = __gcd(f[dep][i].first, a[x]);
    f[dep][tot[dep] ++].first = a[x];
    f[dep][tot[dep] - 1].second = 1;
    int tot1 = 1;
    for (int i = 1; i < tot[dep]; i ++)
        if (f[dep][i].first != f[dep][tot1 - 1].first){
            f[dep][tot1 ++] = f[dep][i];
        } else
            f[dep][tot1 - 1].second += f[dep][i].second;
    tot[dep] = tot1;
    for (int i = 0; i < tot[dep]; i ++)
        ans = (ans + f[dep][i].first * f[dep][i].second) % mod;
    for (auto u:g[x])
        if (u!=fa) {
            for (int j = 0; j < tot[dep];j ++)
                f[dep + 1][j] = f[dep][j];
            tot[dep+1] = tot[dep];
            dfs(u, x, dep + 1);
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i < n ; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0);
    cout<<ans;
    return 0;
}