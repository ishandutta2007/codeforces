#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100011, inf = 1000111222;

struct robot {
    int x, r, q;

    void read() {
        scanf("%d%d%d", &x, &r, &q);
    }

    bool operator < (const robot &r) const {
        return x < r.x;
    }
};

struct query {
    int pos, x, z;

    query(int pos, int x, int z): pos(pos), x(x), z(z) {
    }

    bool operator < (const query &q) const {
        return pos < q.pos;
    }
};

int n, k, l[max_n], r[max_n];
robot a[max_n];
vector<int> q;
vector<int> all[max_n];
vector<query> v[max_n];

long long triv() {
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= r[i]; ++j) {
            if (l[j] <= i && abs(q[a[i].q] - q[a[j].q]) <= k) {
                ++res;
            }
        }
    }
    return res;
}

void prec() {
    for (int i = 0; i < n; ++i) {
        int L = -1, R = i;
        while (R - L > 1) {
            int mid = (L + R) / 2;
            if (a[mid].x + a[i].r >= a[i].x) {
                R = mid;
            } else {
                L = mid;
            }
        }
        l[i] = R;
        L = i;
        R = n;
        while (R - L > 1) {
            int mid = (L + R) / 2;
            if (a[mid].x - a[i].r <= a[i].x) {
                L = mid;
            } else {
                R = mid;
            }
        }
        r[i] = L;
        q.push_back(a[i].q);
    }
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    for (int i = 0; i < n; ++i) {
        a[i].q = lower_bound(q.begin(), q.end(), a[i].q) - q.begin();
        all[a[i].q].push_back(i);
    }
}

int t[max_n], last[max_n], curt;

void clr(int pos) {
    if (last[pos] < curt) {
        last[pos] = curt;
        t[pos] = 0;
    }
}

void update(int i, int x) {
    for (; i < max_n; i = (i | (i + 1))) {
        clr(i);
        t[i] += x;
    }
}

int get_sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        clr(r);
        res += t[r];
    }
    return res;
}

long long solve() {
    for (int i = 0; i < n; ++i) {
        for (int d = -k; d <= k; ++d) {
            //cout << "$" << d + q[a[i].q] << endl;
            auto it = lower_bound(q.begin(), q.end(), d + q[a[i].q]);
            if (it == q.end() || *it != d + q[a[i].q]) {
                continue;
            }
            const int id_q = it - q.begin();
            v[id_q].push_back({r[i], i, 1});
            v[id_q].push_back({i, i, -1});
            //cout << q[id_q] << ": " << i << " " << r[i] << endl;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        sort(v[i].begin(), v[i].end());
        int pos = 0;
        ++curt;
        //cout << endl << endl << "clr\n";
        for (int j = 0; j < v[i].size(); ++j) {
            while (pos < all[i].size() && all[i][pos] <= v[i][j].pos) {
                //cout << "upd " << all[i][pos] << " " << l[all[i][pos]] << endl;
                update(l[all[i][pos]], 1);
                ++pos;
            }
            //cout << v[i][j].z << " $" << get_sum(v[i][j].x) << endl;
            ans += v[i][j].z * get_sum(v[i][j].x);
        }
    }
    return ans;
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

const bool debug = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        n = 100000;
        k = 20;
        for (int i = 0; i < n; ++i) {
            a[i].x = rnd(1, 5);
            a[i].r = rnd(1, 5);
            a[i].q = rnd(1, 5);
        }
        if (0) {
            cout << n << " " << k << endl;
            for (int i = 0; i < n; ++i) {
                cout << a[i].x << " " << a[i].r << " " << a[i].q << endl;
            }
        }
    } else {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            a[i].read();
        }
    }
    sort(a, a + n);
    prec();
    //cout << triv() << endl;
    cout << solve() << endl;
    return 0;
}