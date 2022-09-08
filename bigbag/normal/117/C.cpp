#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 5005, inf = 1111111111;

int n, num[max_n][max_n], Q, used[max_n];
char s[max_n];

int v[max_n], szv, rg[max_n], szrg, szg[max_n], g[max_n][max_n];

void add_edge(int u, int v) {
    num[u][v] = szg[u];
    g[u][szg[u]] = v;
    ++szg[u];
}

void er(int u, int v) {
    int num1 = num[u][v];
    swap(num[u][v], num[u][g[u][szg[u] - 1]]);
    swap(g[u][num1], g[u][szg[u] - 1]);
    --szg[u];
}

void fun() {
    if (szv <= 2) {
        return;
    }
    szrg = 0;
    int poz = 0, mn = abs(2 * szg[v[0]] - szv + 1);
    for (int i = 1; i < szv; ++i) {
        int x = abs(2 * szg[v[i]] - szv + 1);
        if (x < mn) {
            poz = i;
            mn = x;
        }
    }
    int b = v[poz], f = 0;
    ++Q;
    for (int i = 0; i < szg[b]; ++i) {
        used[g[b][i]] = Q;
    }
    used[b] = Q;
    for (int i = 0; i < szv; ++i) {
        if (used[v[i]] < Q) {
            rg[szrg] = v[i];
            ++szrg;
        }
    }
    vector<int> vv1, vv2;
    for (int i = 0; i < szrg; ++i) {
        int a = rg[i];
        vv1.push_back(a);
        for (int j = 0; j < szg[b]; ++j) {
            int c = g[b][j];
            if (f == 0) {
                vv2.push_back(c);
            }
            if (num[c][a] != -1) {
                printf("%d %d %d\n", a + 1, b + 1, c + 1);
                exit(0);
            }
            er(a, c);
        }
        f = 1;
    }
    szv = 0;
    for (int i = 0; i < szg[b]; ++i) {
        v[szv] = g[b][i];
        ++szv;
    }
    for (int i = 0; i < szv; ++i) {
        int a = v[i];
        er(b, a);
    }
    szv = 0;
    for (int i = 0; i < vv1.size(); ++i) {
        v[szv] = vv1[i];
        ++szv;
    }
    vv1.clear();
    fun();
    szv = 0;
    for (int i = 0; i < vv2.size(); ++i) {
        v[szv] = vv2[i];
        ++szv;
    }
    vv2.clear();
    fun();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(num, -1, sizeof(num));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        v[szv] = i;
        ++szv;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                add_edge(i, j);
            }
        }
    }
    fun();
    printf("-1\n");
    return 0;
}