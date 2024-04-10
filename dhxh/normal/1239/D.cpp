#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
const int maxn = 2220000;
vector<int> G[maxn];
int vis[maxn], tmp[maxn], n, m;
int rev(int x){
    return x <= n ? x + n : x - n;
}
bool solve(int x){
    memset(tmp, 0, sizeof(int) * (n * 2 + 20));
    memset(vis, 0, sizeof(int) * (n * 2 + 20));
    queue<int> Q;
    Q.push(x);
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        tmp[x] = tmp[rev(x)] = true;
        for (auto i : G[x]) if (!tmp[i]){
            int j = rev(i);
            vis[j] = true;
            tmp[i] = tmp[rev(i)] = true;
            Q.push(j);
        }
    }
    int tot = accumulate(tmp, tmp + n + 1, 0);
    if (tot == 0 || tot == n)
        return false;
    if (x > n) for (int i = 1; i <= n; ++i)
        tmp[i] ^= 1;
    return true;
}
int main(){
   // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n * 2; ++i)
            G[i].clear();
        for (int i = 0; i < m; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            b += n;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        bool ok = true;
        if (!solve(1)){
            if (!solve(n + 1))
                ok = false;
        }
        if (!ok){
            puts("No");
            continue;
        }
        puts("Yes");
        vector<int> A, B;
        for (int i = 1; i <= n; ++i){
            if (tmp[i])
                A.push_back(i);
            else
                B.push_back(i);
        }
        printf("%d %d\n", A.size(), B.size());
        for (auto i : A) printf("%d ", i);
        printf("\n");
        for (auto i : B) printf("%d ", i);
        printf("\n");
    }
}