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

const int max_n = 500055, inf = 1111111111;

int n;
char s[max_n];
vector<int> q;
int A[26][max_n], b[26][max_n];

void update(int num, int x) {
    for (int i = x; i < n; i = (i | (i + 1))) {
        A[num][i] += (b[num][x] ^ 1) - b[num][x];
    }
    b[num][x] ^= 1;
}

int get_sum(int num, int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += A[num][r];
    }
    return res;
}

int get_sum(int num, int l, int r) {
    if (l == 0) {
        return get_sum(num, r);
    }
    return get_sum(num, r) - get_sum(num, l - 1);
}

int m, r[max_n], poz[max_n], ans[max_n];
vector<int> g[max_n], a[max_n], all[max_n], ans_num[max_n];

void dfs(int v, int len) {
    all[len].push_back(v);
    poz[v] = q.size();
    q.push_back(v);
    r[v] = v;
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i], len + 1);
        if (poz[r[v]] < poz[r[g[v][i]]]) {
            r[v] = r[g[v][i]];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
    }
    scanf("%s", s);
    for (int i = 0; i < m; ++i) {
        int v, h;
        scanf("%d%d", &v, &h);
        a[h].push_back(v);
        ans_num[h].push_back(i);
    }
    dfs(1, 1);
    /*for (int i = 0; i < q.size(); ++i) {
        cout << q[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        cout << poz[i] << " " << poz[r[i]] << endl;
    }*/
    for (int i = 1; i <= n; ++i) {
        //cout << i << " : ";
        for (int j = 0; j < all[i].size(); ++j) {
            //cout << all[i][j] << " ";
            update(s[q[poz[all[i][j]]] - 1] - 'a', poz[all[i][j]]);
        }
        //cout << endl;
        for (int j = 0; j < a[i].size(); ++j) {
            int v = a[i][j];
            int f = 0;
            for (int k = 0; k < 26; ++k) {
                int x = get_sum(k, poz[v], poz[r[v]]);
                if (x % 2 == 1) {
                    ++f;
                    if (f > 1) {
                        break;
                    }
                }
            }
            if (f <= 1) {
                ans[ans_num[i][j]] = 1;
            }
        }
        for (int j = 0; j < all[i].size(); ++j) {
            //cout << all[i][j] << " ";
            update(s[q[poz[all[i][j]]] - 1] - 'a', poz[all[i][j]]);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ans[i]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}