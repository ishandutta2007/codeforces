#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2000010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

struct Tree {
    int v[MAXN];
    int x[MAXN];

    void built(int t, int l, int r) {
        if (l == r) {
            x[t] = v[l];
            return ;
        }
        int mid = (l + r) / 2;
        built(t + t, l, mid);
        built(t + t + 1, mid + 1, r);
        x[t] = gcd(x[t + t], x[t + t + 1]);
    }

    int query(int t, int a, int b, int l, int r, int val) {
        if (x[t] % val == 0) return 0;
        if (l == r) return 1;
        
        int mid = (l + r) / 2;
        if (a <= l && r <= b) {
            if (x[t + t] % val != 0 && x[t + t + 1] % val != 0) return 2;
            if (x[t + t] % val != 0) return query(t + t, a, b, l, mid, val);
            if (x[t + t + 1] % val != 0) return query(t + t + 1, a, b, mid + 1, r, val);
            return 0;
        }

        int ans = 0;
        if (a <= mid) ans += query(t + t, a, b, l, mid, val);
        if (mid + 1 <= b) ans += query(t + t + 1, a, b, mid + 1, r, val);
        return ans;
    }

    void update(int t, int a, int l, int r, int val) {
        if (l == r) {
            x[t] = v[l] = val;
            return ;
        }
        int mid = (l + r) / 2;
        if (a <= mid) update(t + t, a, l, mid, val); else update(t + t + 1, a, mid + 1, r, val);
        x[t] = gcd(x[t + t], x[t + t + 1]);
    }
};

Tree T;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> T.v[i];
    T.built(1, 1, N);
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            if (T.query(1, l, r, 1, N, x) < 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            int l, x;
            cin >> l >> x;
            T.update(1, l, 1, N, x);
        }
    }

    return 0;
}