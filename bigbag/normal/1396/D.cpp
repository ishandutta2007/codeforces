#include <bits/stdc++.h>

using namespace std;

const int max_n = 2044, mod = 1000000007;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mx[4 * max_n];
    long long sum[4 * max_n], sumsz[4 * max_n];

    void build(int v, int l, int r, T a[], T sz[]) {
        f[v] = -1;
        if (l == r) {
            sumsz[v] = sz[l];
            sum[v] = a[l] * sumsz[v];
            //cout << "@@" << l << " " << sum[v] << endl;
            mx[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a, sz);
        build(2 * v + 1, mid + 1, r, a, sz);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        sumsz[v] = sumsz[2 * v] + sumsz[2 * v + 1];
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v] != -1) {
            sum[2 * v] = f[v] * sumsz[2 * v];
            sum[2 * v + 1] = f[v] * sumsz[2 * v + 1];
            mx[2 * v] = f[v];
            mx[2 * v + 1] = f[v];
            f[2 * v] = f[v];
            f[2 * v + 1] = f[v];
            f[v] = -1;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] = value;
            mx[v] = value;
            sum[v] = value * sumsz[v];
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }

    int get_more_eq(int v, int tl, int tr, int x) {
        if (tl == tr) {
            return tl;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (mx[2 * v] >= x) {
            return get_more_eq(2 * v, tl, mid, x);
        }
        return get_more_eq(2 * v + 1, mid + 1, tr, x);
    }
};

struct point {
    int x, y, c;

    bool operator < (const point &p) const {
        return x < p.x || x == p.x && y < p.y;
    }
};

int n, k, L, nxt[max_n], mxnxt[max_n];
point p[max_n];
vector<int> vx, vy;
multiset<int> all_pos[max_n];
segment_tree<int> t;
int valnxt[max_n], sumsz[max_n];

int compress(const vector<int> &v, int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> L;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].c;
        --p[i].c;
        vx.push_back(p[i].x);
        vy.push_back(p[i].y);
        /*if (p[i].y) {
            vy.push_back(p[i].y - 1);
        }*/
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    vy.push_back(L);
    for (int i = 0; i < n; ++i) {
        p[i].x = compress(vx, p[i].x);
        p[i].y = compress(vy, p[i].y);
    }
    long long ans = 0;
    sort(p, p + n);
    long long lastx = -1;
    for (int i = 0; i < vy.size(); ++i) {
        sumsz[i] = vy[i] + (i + 1 < vy.size());
        if (i) {
            sumsz[i] -= vy[i - 1] + 1;
        }
        //cout << sumsz[i] << " ";
    }
    //cout << endl;
    for (int i = 0; i < n; ++i) {
        //cout << "i = " << i << endl;
        long long slx = vx[p[i].x] - lastx;
        vector<pair<int, int>> v;
        for (int j = 0; j < k; ++j) {
            all_pos[j].clear();
            all_pos[j].insert(-1);
            all_pos[j].insert(vy.size() - 1);
        }
        for (int j = i; j < n; ++j) {
            v.push_back({p[j].y, p[j].c});
            all_pos[p[j].c].insert(p[j].y);
        }
        sort(v.rbegin(), v.rend());
        int pos = 0;
        fill(nxt, nxt + k, vy.size() - 1);
        multiset<int> allnxt(nxt, nxt + k);
        mxnxt[vy.size() - 1] = vy.size() - 1;
        valnxt[vy.size() - 1] = L;
        for (int j = vy.size() - 2; j >= 0; --j) {
            while (pos < v.size() && v[pos].first == j) {
                allnxt.erase(allnxt.find(nxt[v[pos].second]));
                //cout << "$$$" << j << " " << v[pos].first << " " << v[pos].second << endl;
                nxt[v[pos].second] = j;
                allnxt.insert(j);
                ++pos;
            }
            mxnxt[j] = *allnxt.rbegin();
            valnxt[j] = vy[mxnxt[j]];
        }
        t.build(1, 0, vy.size() - 1, valnxt, sumsz);
        /*for (int j = 0; j < vy.size(); ++j) {
            cout << valnxt[j] << " ";
        }
        cout << endl;*/
        int lastrx = L;
        for (int j = n - 1; j >= i; --j) {
            long long tot = 1LL * L * L - t.sum[1];
            //cout << i << " " << j << ": " << tot << "   " << slx << " " << lastrx - vx[p[j].x] << endl;
            ans += mul(slx, mul(lastrx - vx[p[j].x], tot % mod));

            auto nxt = all_pos[p[j].c].lower_bound(p[j].y);
            auto pr = nxt;
            --pr;
            ++nxt;
            int pos = t.get_more_eq(1, 0, vy.size() - 1, vy[*nxt]);
            //cout << "try upd: " << (*pr) << " " << p[j].y << " " << (*nxt) << ", pos = " << pos << endl;
            if (*pr + 1 < pos) {
                //cout << "upd " << endl;
                t.update(1, 0, vy.size() - 1, *pr + 1, pos - 1, vy[*nxt]);
            }
            all_pos[p[j].c].erase(--nxt);
            lastrx = vx[p[j].x];
        }
        lastx = vx[p[i].x];
    }
    ans %= mod;
    cout << ans << "\n";
    return 0;
}