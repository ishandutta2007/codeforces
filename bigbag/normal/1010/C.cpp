#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, k, x, used[max_n];
vector<int> all, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    while (n--) {
        scanf("%d", &x);
        x = __gcd(x, k);
        if (used[x] == 0) {
            used[x] = 1;
            all.push_back(x);
        }
    }
    memset(used, 0, sizeof(used));
    queue<int> q;
    q.push(0);
    used[0] = 1;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        ans.push_back(x);
        for (int add : all) {
            int to = (x + add) % k;
            if (used[to] == 0) {
                used[to] = 1;
                q.push(to);
            }
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}