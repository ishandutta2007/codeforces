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

const int max_n = 111111, inf = 1111111111;

int n, a[max_n], d[max_n];
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(d, -1, sizeof(d));
    scanf("%d", &n);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < max_n) {
            g[a[i]].push_back(i);
        }
        if (i == 0 || i == n - 1) {
            q.push(i);
            d[i] = 1;
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (ans < d[v]) {
            ans = d[v];
            for (int i = 0; i < g[ans].size(); ++i) {
                int poz = g[ans][i];
                if (d[poz] == -1) {
                    d[poz] = ans;
                    q.push(poz);
                }
            }
        }
        if (v > 0 && d[v - 1] == -1) {
            d[v - 1] = d[v] + 1;
            q.push(v - 1);
        }
        if (v + 1 < n && d[v + 1] == -1) {
            d[v + 1] = d[v] + 1;
            q.push(v + 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}