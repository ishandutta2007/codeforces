/**
 *  created: 25/12/2020, 14:50:45
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 500555, inf = 1000111222;

template<typename T>
struct segment_tree {
    T mx[4 * max_n];

    void build(int v, int l, int r) {
        if (l == r) {
            mx[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            mx[v] = max(mx[v], value);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int t, n, a[max_n], dp[max_n];
segment_tree<int> t1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        t1.build(1, 0, n);
        set<pair<int, int>> q;
        q.insert({0, 0});
        for (int i = 1; i <= n; ++i) {
            dp[i] = 1 + t1.get_max(1, 0, n, 0, a[i]);
            while (!q.empty()) {
                auto it = q.begin();
                if (it->first > a[i]) {
                    break;
                }
                int pos = it->second;
                t1.update(1, 0, n, a[pos], dp[pos] + 1);;
                q.erase(it);
            }
            q.insert({a[i], i});
            t1.update(1, 0, n, a[i], dp[i]);
            //cout << i << ": " << dp1[i] << " " << dp2[i] << endl;
        }
        printf("%d\n", t1.get_max(1, 0, n, 0, n));
    }
    return 0;
}