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

const int max_n = 222222, inf = 1000000001;
const long long MX = 1111111111111111111LL;

long long ans = MX;
int n, k, b, c, a[max_n], poz[5];
vector<int> v[5];
vector<long long> sum[5];

long long get(int x, int y) {
    x = y - x;
    long long res = (1LL * x * c);
    int q = x / 5;
    int w = x % 5;
    res = min(res, 1LL * q * b + 1LL * w * c);
    return res;
}

long long get_sum(int num, int l, int r) {
    if (l == 0) {
        return sum[num][r];
    }
    return sum[num][r] - sum[num][l - 1];
}

long long get(int num, int l, int r, int x) {
    long long s = get_sum(num, l, r);
    s = 1LL * x * (r - l + 1) - s;
    long long res = s * c;
    int o = x % 5;
    if (num <= o) {
        o -= num;
    } else {
        o -= num;
        o += 5;
    }
    o %= 5;
    s -= 1LL * (r - l + 1) * o;
    s /= 5;
    res = min(res, s * b + 1LL * (1LL * (r - l + 1) * o) * c);
    return res;
}

void add(int x) {
    v[x % 5].push_back(x);
    sum[x % 5].push_back(x);
    int sz = sum[x % 5].size();
    if (sz > 1) {
        sum[x % 5][sz - 1] += sum[x % 5][sz - 2];
    }
}

int get_o(int x, int o) {
    while (x % 5 != o) {
        ++x;
    }
    return x;
}

long long fun(int x) {
    long long res = 0;
    for (int i = 0; i < 5; ++i) {
        if (poz[i] < v[i].size()) {
            res += get(i, poz[i], v[i].size() - 1, x);
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &k, &b, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] += inf;
    }
    sort(a, a + n);
    for (int o = 0; o < 5; ++o) {
        for (int i = 0; i < 5; ++i) {
            v[i].clear();
            sum[i].clear();
        }
        for (int i = 0; i < k; ++i) {
            add(a[i]);
        }
        int x = get_o(a[k - 1], o);
        for (int i = 0; i < 5; ++i) {
            poz[i] = 0;
        }
        ans = min(ans, fun(x));
        for (int i = k; i < n; ++i) {
            x = get_o(a[i], o);
            add(a[i]);
            long long q = get(a[i], x);
            pair<long long, int> p = make_pair(-MX, a[i] % 5);
            for (int j = 0; j < 5; ++j) {
                if (poz[j] < v[j].size()) {
                    long long w = get(v[j][poz[j]], x);
                    if (w > p.first) {
                        p = make_pair(w, j);
                    }
                }
            }
            ++poz[p.second];
            ans = min(ans, fun(x));
        }
    }
    printf("%I64d\n", ans);
    return 0;
}