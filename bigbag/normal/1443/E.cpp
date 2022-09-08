#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_f = 16;

int n, q, a[max_n];
long long f[max_f], sum[max_n];

long long get_sum(int l, int r) {
    if (!l) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

long long get_num(const vector<int> &v) {
    long long res = 0;
    for (int i = 0; i < v.size(); ++i) {
        int cnt = 0;
        for (int j = i + 1; j < v.size(); ++j) {
            cnt += v[i] > v[j];
        }
        res += cnt * f[v.size() - i - 1];
    }
    return res;
}

vector<int> get_p(int n, long long num) {
    vector<char> used(n, 0);
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        int x = num / f[n - i - 1];
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                if (!x) {
                    used[j] = 1;
                    res.push_back(j);
                    break;
                }
                --x;
            }
        }
        num %= f[n - i - 1];
    }
    return res;
}

void calc_sum() {
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = a[i] + sum[i - 1];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    f[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        f[i] = f[i - 1] * i;
    }
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    calc_sum();
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 2) {
            int x;
            scanf("%d", &x);
            int len = min(max_f - 1, n);
            vector<int> elems({a + n - len, a + n});
            long long num = get_num(elems);
            if (num + x < f[len]) {
                num += x;
                vector<int> v = get_p(len, num);
                sort(elems.begin(), elems.end());
                for (int i = 0; i < elems.size(); ++i) {
                    a[n - len + i] = elems[v[i]];
                    sum[n - len + i] = a[n - len + i];
                    if (n - len + i) {
                        sum[n - len + i] += sum[n - len + i - 1];
                    }
                }
            } else {
                while (x--) {
                    next_permutation(a, a + n);
                }
                calc_sum();
            }
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            --r;
            printf("%lld\n", get_sum(l, r));
        }
    }
    return 0;
}