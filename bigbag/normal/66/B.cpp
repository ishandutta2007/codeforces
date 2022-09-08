#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 111111111;

int n, cnt, a[max_n], used[max_n];

void bfs(int v) {
    used[v] = 1;
    ++cnt;
    if (v - 1 >= 0 && used[v - 1] == 0 && a[v - 1] <= a[v]) {
        bfs(v - 1);
    }
    if (v + 1 < n && used[v + 1] == 0 && a[v + 1] <= a[v]) {
        bfs(v + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cnt = 0;
        memset(used, 0, sizeof(used));
        bfs(i);
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}