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

const int max_n = 222222, max_x = 1111111, inf = 1111111111;

int n, a[max_n], b[max_n], ans[max_n];
int used1[max_x], used2[max_x];
set<int> q;

void dfs(int poz, int x) {
    //cout <<poz << " " << x << endl;
    string qqq;
    cin >> qqq;
    ans[poz] = x;
    if (used1[x] != -1 && poz + 2 <= n) dfs(poz + 2, b[used1[x]]);
}

void dfs2(int poz, int x) {
    //cout <<poz << " " << x << endl;
    ans[poz] = x;
    if (poz - 2 > 0 && used2[x] != -1) dfs2(poz - 2, a[used2[x]]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    memset(used1, -1, sizeof(used1));
    memset(used2, -1, sizeof(used2));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        used1[a[i]] = i;
        used2[b[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            dfs(2, b[i]);
            break;
        }
    }
    if (n % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0) {
                dfs2(n - 1, a[i]);
                break;
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            q.insert(b[i]);
            q.insert(a[i]);
        }
        for (int i = 0; i < n; ++i) {
            q.erase(b[i]);
        }
        int x = *q.begin();
        dfs(1, x);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}