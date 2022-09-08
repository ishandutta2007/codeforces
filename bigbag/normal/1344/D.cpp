#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int max_n = 100111;
const long long inf = 3000111222000111222LL;

int n, a[max_n], ans[max_n];
long long k;

inline long long get_val(int a, int mid) {
    return a - 3LL * mid * (mid - 1) - 1;
}

int get_mx(long long x, int a) {
    int l = 0, r = a + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (get_val(a, mid) >= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

long long get_cnt(long long x) {
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += get_mx(x, a[i]);
    }
    return res;
}

void test() {
    cout << accumulate(ans, ans + n, 0LL) << " " << k << endl;
    long long x = 0;
    for (int i = 0; i < n; ++i) {
        x += 1LL * ans[i] * (a[i] - 1LL * ans[i] * ans[i]);
    }
    cout << "val = " << x << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long l = -inf, r = inf;
    while (r - l > 1) {
        long long mid = l + (r - l) / 2;
        if (get_cnt(mid) <= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    int need = k - get_cnt(r);
    //cout << "need = " << need << endl;
    //cout << "r = " << r << endl;
    for (int i = 0; i < n; ++i) {
        ans[i] = get_mx(r, a[i]);
        //cout << "#" << get_val(a[i], ans[i] + 1) << endl;
        if (ans[i] < a[i] && need && get_val(a[i], ans[i] + 1) == l) {
            ++ans[i];
            --need;
        }
        printf("%d ", ans[i]);
    }
    puts("");
    //test();
    return 0;
}