#include <bits/stdc++.h>

using namespace std;

const int max_n = 15, inf = 1000111222;
const int max_k = 5055;
const int max_mask = 1 << max_n;

int n, dp[max_mask];
map<long long, int> num;
vector<int> a[max_n + 2], all[max_n + 2], xs[max_n + 2];
vector<pair<int, int>> res[max_mask];
int ans_x[max_n + 2], ans_to[max_n + 2];
long long s, tot[max_n];

void no() {
    puts("No");
    exit(0);
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void add(int mask) {
    //cout << "!!!" << mask << endl;
    for (auto p : res[mask]) {
        const int x = p.first;
        const int id = num[x];
        ans_x[id] = x;
        ans_to[id] = p.second;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        a[i].resize(k);
        for (int &x : a[i]) {
            scanf("%d", &x);
            num[x] = i;
            s += x;
            tot[i] += x;
        }
    }
    if (s % n) {
        no();
    }
    s /= n;
    for (int i = 0; i < n; ++i) {
        for (int x : a[i]) {
            int mask = 0, cur = i, last = x;
            vector<pair<int, int>> v;
            while (!get_bit(mask, i)) {
                long long y = s + last - tot[cur];
                if (!num.count(y)) {
                    break;
                }
                int id = num[y];
                if (get_bit(mask, id)) {
                    break;
                }
                if (cur == id) {
                    if (cur != i || last != y) {
                        break;
                    }
                }
                if (id == i && y != x) {
                    break;
                }
                v.push_back({y, cur});
                mask |= 1 << id;

                cur = id;
                last = y;
            }
            if (get_bit(mask, i)) {
                /*cout << "$" << mask << " " << i << ", x = " << x << ": ";
                for (auto p : v) {
                    cout << "(" << p.first << " " << p.second << ") ";
                }
                cout << endl;*/
                res[mask] = v;
                all[i].push_back(mask);
                xs[i].push_back(x);
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int mask = 0; mask + 1 < (1 << n); ++mask) {
        if (dp[mask] == -1) {
            continue;
        }
        int first = 0;
        for (int i = 0; i < n; ++i) {
            if (!get_bit(mask, i)) {
                first = i;
                break;
            }
        }
        for (int nxt : all[first]) {
            if ((mask & nxt) == 0) {
                dp[mask | nxt] = mask;
            }
        }
    }
    int full = (1 << n) - 1;
    if (dp[full] == -1) {
        no();
    }
    puts("Yes");
    while (full) {
        int mask = full ^ dp[full];
        add(mask);
        full = dp[full];
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", ans_x[i], ans_to[i] + 1);
    }
    return 0;
}