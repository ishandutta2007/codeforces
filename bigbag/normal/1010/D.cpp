#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, parent[max_n], to[max_n][2];
char tp[max_n], s[6];
bool dp[max_n], f[max_n], value[max_n];

bool op(bool a, bool b, char tp) {
    if (tp == 'A') {
        return a & b;
    } else if (tp == 'O') {
        return a | b;
    }
    return a ^ b;
}

int get_dp(int v) {
    if (tp[v] == 'N') {
        return !dp[to[v][0]];
    }
    return op(dp[to[v][0]], dp[to[v][1]], tp[v]);
}

void calc_dp(int v) {
    if (tp[v] == 'I') {
        dp[v] = value[v];
        return;
    }
    if (tp[v] == 'N') {
        calc_dp(to[v][0]);
    } else {
        calc_dp(to[v][0]);
        calc_dp(to[v][1]);
    }
    dp[v] = get_dp(v);
}

void calc_f(int v) {
    if (v == 1) {
        f[v] = 1;
    } else {
        dp[v] ^= 1;
        //cout << v << " " << get_dp(parent[v]) << " " << dp[parent[v]] << endl;
        if (get_dp(parent[v]) != dp[parent[v]]) {
            f[v] = f[parent[v]];
        }
        dp[v] ^= 1;
    }
    if (tp[v] == 'A' || tp[v] == 'X' || tp[v] == 'O') {
        calc_f(to[v][0]);
        calc_f(to[v][1]);
    } else if (tp[v] == 'N') {
        calc_f(to[v][0]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        tp[i] = s[0];
        if (tp[i] == 'A' || tp[i] == 'X' || tp[i] == 'O') {
            scanf("%d%d", &to[i][0], &to[i][1]);
            parent[to[i][0]] = i;
            parent[to[i][1]] = i;
        } else if (tp[i] == 'N') {
            scanf("%d", &to[i][0]);
            parent[to[i][0]] = i;
        } else {
            int val;
            scanf("%d", &val);
            value[i] = val;
        }
    }
    calc_dp(1);
    calc_f(1);
    for (int i = 1; i <= n; ++i) {
        //cout << i << " " << f[i] << endl;
        if (tp[i] == 'I') {
            printf("%d", dp[1] ^ f[i]);
        }
    }
    printf("\n");
    return 0;
}