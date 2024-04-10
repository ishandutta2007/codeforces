#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, k, val[max_n], p[max_n], sum[max_n], f[max_n], is_fixed[max_n];
char s[max_n];
vector<int> g[max_n], comp[max_n];
int ans;

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

int get_val(int v) {
    return val[v] ^ f[find_set(v)];
}

int get_sum(int root) {
    if (f[root]) {
        return comp[root].size() - sum[root];
    }
    return sum[root];
}

void update_all(int root) {
    //cout << "$" << root << endl;
    ans -= get_sum(root);
    f[root] ^= 1;
    ans += get_sum(root);
}

void update_all_all(int root) {
    sum[root] = comp[root].size() - sum[root];
    for (int v : comp[root]) {
        val[v] ^= 1;
    }
    f[root] ^= 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &k, s);
    for (int i = 0; i < k; ++i) {
        int cnt;
        scanf("%d", &cnt);
        while (cnt--) {
            int v;
            scanf("%d", &v);
            --v;
            g[v].push_back(i);
        }
    }
    for (int i = 0; i < k; ++i) {
        val[i] = 0;
        comp[i].push_back(i);
        p[i] = i;
        sum[i] = 0;
        f[i] = 0;
        is_fixed[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        int x = s[i] - '0';
        x ^= 1;
        if (g[i].empty()) {
        } else if (g[i].size() == 1) {
            int root = find_set(g[i][0]);
            is_fixed[root] = 1;
            if (get_val(g[i][0]) != x) {
                update_all(root);
            }
        } else {
            int v1 = g[i][0];
            int v2 = g[i][1];
            int r1 = find_set(v1);
            int r2 = find_set(v2);
            if (r1 != r2) {
                if (comp[r1].size() < comp[r2].size()) {
                    swap(r1, r2);
                    swap(v1, v2);
                }
                //cout << r1 << " " << r2 << ": " << get_val(v1) << " " << get_val(v2) << ", x = " << x << endl;
                if ((get_val(v1) ^ get_val(v2)) != x) {
                    if (is_fixed[r1]) {
                        update_all(r2);
                    } else {
                        update_all(r1);
                    }
                }
                is_fixed[r1] = is_fixed[r1] | is_fixed[r2];
                if (f[r1] != f[r2]) {
                    update_all_all(r2);
                }
                for (int v : comp[r2]) {
                    comp[r1].push_back(v);
                }
                sum[r1] += sum[r2];
                if (!is_fixed[r1] && get_sum(r1) > comp[r1].size() - get_sum(r1)) {
                    update_all(r1);
                }
                p[r2] = r1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}