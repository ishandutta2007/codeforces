
#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main

// #define constexpr(...) (__VA_ARGS__)
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream &operator<<(ostream &out, const __VA_ARGS__ &u)
// DEBUGING TEMPLETE
// ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "[" #val " = " << (val) << "] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG
#define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#define DB() debug_block CONCAT(dbbl, __LINE__)
int __db_level = 0;
struct debug_block {
    debug_block() {
        clog << "{" << endl;
        ++__db_level;
    }
    ~debug_block() {
        --__db_level;
        clog << "}" << endl;
    }
};
#else
#define clog                                                                   \
    if (0)                                                                     \
    cerr
#define DB(...)
#endif

template <class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream &>::type
operator<<(ostream &out, const Con &con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template <size_t i, class T>
ostream &print_tuple_utils(ostream &out, const T &tup) {
    if constexpr (i == tuple_size<T>::value)
        return out << ")";
    else
        return print_tuple_utils<i + 1, T>(
            out << (i ? ", " : "(") << get<i>(tup), tup);
}
template <class... U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE
// ////////////////////////////////////////////////////////////////}}}

struct Node {
    array<array<int, 3>, 2> par;
    int comp_cnt;
    friend print_op(Node) {
        return out << "(" << u.comp_cnt << "; " << u.par << ")";
    }
    Node() { comp_cnt = -1; }
    Node(int col_mask) {
        if (col_mask == 0b101) {
            par[0][0] = par[1][0] = 0;
            par[0][2] = par[1][2] = 1;
            par[0][1] = par[1][1] = -1;
            comp_cnt = 2;
        } else {
            comp_cnt = col_mask != 0;
            rep(i, 0, 3) if ((col_mask >> i) & 1) { par[0][i] = par[1][i] = 0; }
            else {
                par[0][i] = par[1][i] = -1;
            }
        }
        clog << db(col_mask) << *this << endl;
    }

    Node(Node l, Node r) {
        DB();
        clog << db(l) << endl;
        clog << db(r) << endl;
        if (l.comp_cnt == -1) {
            *this = r;
            return;
        }
        if (r.comp_cnt == -1) {
            *this = l;
            return;
        }
        comp_cnt = l.comp_cnt + r.comp_cnt;
        rep(i, 0, 2) rep(f, 0, 3) {
            if (l.par[i][f] != -1) {
                l.par[i][f] += 6;
            }
        }
        rep(i, 0, 3) {
            if (l.par[1][i] != -1 and r.par[0][i] != -1 and l.par[1][i] != r.par[0][i]) {
                int new_id = l.par[1][i];
                l.upd_label(r.par[0][i], new_id);
                r.upd_label(r.par[0][i], new_id);
                --comp_cnt;
            }
        }
        clog << db(l) << endl;
        clog << db(r) << endl;

        vector<int> values;
        rep(i, 0, 3) {
            par[0][i] = l.par[0][i];
            par[1][i] = r.par[1][i];
            if (par[0][i] != -1)
                values.push_back(par[0][i]);
            if (par[1][i] != -1)
                values.push_back(par[1][i]);
        }
        sort(all(values));
        rep(i, 0, 3) {
            if (par[0][i] != -1) {
                par[0][i] =
                    (int)(lower_bound(all(values), par[0][i]) - values.begin());
            }
            if (par[1][i] != -1) {
                par[1][i] =
                    (int)(lower_bound(all(values), par[1][i]) - values.begin());
            }
        }
        clog << db(*this) << endl;
    }

    void upd_label(int old_lab, int new_lab) {
        rep(i, 0, 2) rep(f, 0, 3) if (par[i][f] == old_lab) par[i][f] = new_lab;
    }
};

const int maxn = 501010;
Node it[maxn * 2];
int n;
string a[3];
void build() {
    rep(i, 0, n) {
        int mask =
            (a[0][i] - '0') << 2 | (a[1][i] - '0') << 1 | (a[2][i] - '0');
        it[i + n] = Node(mask);
    }
    for (int i = n; i--;) {
        it[i] = Node(it[2 * i], it[2 * i + 1]);
    }
}

Node get(int l, int r) {
    Node left, right;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            left = Node(left, it[l++]);
        if (r & 1)
            right = Node(it[--r], right);
    }
    return Node(left, right);
}

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    rep(i, 0, 3) cin >> a[i];
    build();

    int q;
    cin >> q;
    while (q--) {
        DB();
        int l, r;
        cin >> l >> r;
        --l;
        clog << db(l) << db(r) << endl;
        auto ans = get(l, r);
        cout << ans.comp_cnt << '\n';
    }

    return 0;
}