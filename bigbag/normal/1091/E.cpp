#include <bits/stdc++.h>

using namespace std;

int rnd() {
    return ((rand() % (1 << 16)) << 16) + (rand() % (1 << 16));
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

const int max_n = 505555, inf = 1000111222;

int n, a[max_n], b[max_n];

void modify(int pos) {
    while (pos > 0 && b[pos] > b[pos - 1]) {
        swap(b[pos], b[pos - 1]);
        --pos;
    }
}

long long ok(int n, int x) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }
    b[n] = x;
    ++n;
    modify(n - 1);
    long long sum = 0;
    long long res = -1e18;

    int cnt_ok = 0;
    int pos = n - 1;
    long long sum_ok = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (b[i] < i) {
            --cnt_ok;
            sum_ok -= b[i];
        }
        sum += b[i];
        while (pos > i && b[pos] < i + 1) {
            ++cnt_ok;
            sum_ok += b[pos];
            --pos;
        }
        long long q = 1LL * i * (i + 1) + sum_ok + 1LL * (i + 1) * (n - 1 - i - cnt_ok);
        res = max(res, sum - q);
    }
    return res;
}

vector<int> solve() {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    int st = sum % 2;
    if (0) {
        for (int i = st; i <= n; i += 2) {
            cout << ok(n, i) << " ";
        }
        cout << endl;
    }
    int l = 0, r = n;
    while (st + 2 * r > n) {
        --r;
    }
    ++r;
    int val = ok(n, st);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ok(n, st + 2 * mid) != val - 2 * mid) {
            r = mid;
        } else {
            l = mid;
        }
    }

    st += 2 * l;
    //cout << "#" << st << endl;
    if (ok(n, st) > 0) {
        st += 2;
    }
    if (st > n) {
        return {};
    }
    if (ok(n, st) > 0) {
        return {};
    }
    l = 0;
    r = n;
    while (st + 2 * r > n) {
        --r;
    }
    ++r;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ok(n, st + 2 * mid) <= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int to = st + 2 * l;


    l = 0;
    r = n;
    while (st - 2 * r < 0) {
        --r;
    }
    ++r;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ok(n, st - 2 * mid) <= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int from = st - 2 * l;
    vector<int> res;
    for (int i = from; i <= to; i += 2) {
        res.push_back(i);
    }
    return res;
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    reverse(a, a + n);
}

void gener() {
    n = rnd(1, 50);
    n = 500000;
    for (int i = 0; i < n; ++i) {
        a[i] = rnd(0, n);
    }
    sort(a, a + n);
    reverse(a, a + n);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    read();
    //srand(time(NULL));
    //gener();
    const vector<int> &ans = solve();
    if (ans.empty()) {
        printf("-1\n");
    } else {
        for (int x : ans) {
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}