#include <bits/stdc++.h>

using namespace std;

const int max_n = 400444, inf = 1000111222;

int n, a[max_n], sum[max_n];
vector<int> v[2];
int ans;

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int get_sum(int l, int r) {
    if (r < 0) {
        return 0;
    }
    if (!l) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int get_cnt(int l, int r, int tp) {
    if (tp) {
        return get_sum(l, r);
    }
    return r - l + 1 - get_sum(l, r);
}

/*int triv() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            res ^= (a[i] + a[j]);
        }
    }
    return res;
}*/

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    //cout << triv() << endl;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        if (get_bit(a[i], 0)) {
            ++c1;
        } else {
            ++c0;
        }
    }
    if (c1 % 2 && c0 % 2) {
        ans = 1;
    }
    int mask = 0;
    for (int b = 0; b < 25; ++b) {
        mask += 1 << b;
        v[0].clear();
        v[1].clear();
        for (int i = 0; i < n; ++i) {
            v[get_bit(a[i], b)].push_back(a[i]);
        }
        n = 0;
        for (int f = 0; f < 2; ++f) {
            for (int x : v[f]) {
                a[n++] = x;
            }
        }
        for (int i = 0; i < n; ++i) {
            sum[i] = get_bit(a[i], b + 1);
            if (i) {
                sum[i] += sum[i - 1];
            }
        }
        int pos = 0;
        long long cnt = 0;
        for (int i = n - 1; i > 0; --i) {
            pos = min(pos, i - 1);
            while (pos < i && (a[pos] & mask) + (a[i] & mask) < (1 << (b + 1))) {
                ++pos;
            }
            cnt += get_cnt(pos, i - 1, get_bit(a[i], b + 1));
            cnt += get_cnt(0, pos - 1, !get_bit(a[i], b + 1));
        }
        cnt %= 2;
        ans += cnt * (1 << (b + 1));
    }
    printf("%d\n", ans);
    return 0;
}