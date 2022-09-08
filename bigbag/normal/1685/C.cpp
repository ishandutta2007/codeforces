/**
 *  created: 25/05/2022, 21:20:00
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mx[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        f[v] = 0;
        if (l == r) {
            mx[v] = -a[l + 1];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mx[2 * v] += f[v];
            mx[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mx[v] += value;
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
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }

    int get_last(int v, int tl, int tr, int x) { // >= x
        if (mx[v] < x) {
            return -1;
        }
        if (tl == tr) {
            return tl;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        int res = get_last(2 * v + 1, mid + 1, tr, x);
        if (res == -1) {
            res = get_last(2 * v, tl, mid, x);
        }
        return res;
    }
};

int t, n, suf[max_n], pref[max_n], ok_pref[max_n], mn_suf[max_n];
string s;
segment_tree<int> st;

int get_val(char c) {
    if (c == ')') {
        return -1;
    }
    return 1;
}

bool solve0() {
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        bal += get_val(s[i]);
        if (bal < 0) {
            return false;
        }
    }
    cout << "0\n";
    return true;
}

bool solve1(int add1 = -1, int add2 = -1) {
    suf[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + get_val(s[i]);
    }
    ok_pref[0] = 1;
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + get_val(s[i]);
        ok_pref[i + 1] = ok_pref[i] && (pref[i + 1] >= 0);
    }
    st.build(1, 0, n - 1, suf);
    mn_suf[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        mn_suf[i] = min(pref[i + 1], mn_suf[i + 1]);
    }
    vector<pair<int, int>> v;
    v.push_back({n, -inf});
    for (int i = n - 1; i >= 0; --i) {
        while (suf[i] < v.back().second) {
            st.update(1, 0, n - 1, v.back().first, v[v.size() - 2].first - 1, suf[i] - v.back().second);
            v.pop_back();
        }
        v.push_back({i, suf[i]});
        st.update(1, 0, n - 1, i, i, suf[i]);
        if (ok_pref[i]) {
            int last = st.get_last(1, 0, n - 1, -pref[i]);
            //cout << i + 1 << " " << last + 1 << ":    " << pref[last + 1] << " " << mn_suf[last + 1] << endl;
            if (i <= last && mn_suf[last + 1] >= 0) {
                if (add1 == -1) {
                    cout << 1 << "\n";
                } else {
                    cout << 2 << "\n" << add1 << " " << add2 << "\n";
                }
                cout << i + 1 << " " << last + 1 << "\n";
                //reverse(s.begin() + i, s.begin() + last + 1);
                //cout << s << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (0) {
        mt19937 gen;
        while (true) {
            n = gen() % 200 + 1;
            s = "";
            for (int i = 0; i < n; ++i) {
                s += "()";
            }
            n *= 2;
            shuffle(s.begin(), s.end(), gen);
            string ks = s;
            if (!solve0() && !solve1()) {
                const int pos = max_element(pref, pref + n + 1) - pref;
                reverse(s.begin(), s.begin() + pos);
                if (!solve1()) {
                    cout << ks << endl;
                    exit(228);
                }
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> s;
        n *= 2;
        if (solve0()) {
        } else if (solve1()) {
        } else {
            //reverse(s.begin(), s.end());
            const int pos = max_element(pref, pref + n + 1) - pref;
            reverse(s.begin(), s.begin() + pos);
            assert(solve1(1, pos));
            //solve2();
        }
    }
    return 0;
}