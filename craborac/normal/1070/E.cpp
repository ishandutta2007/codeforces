#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

std::mt19937 rnd(31031999);

#define int int64_t

struct node {
    node(int i, int v) {
        ind = i;
        val = v;
        cnt = 1;
        sum_val = val;
        prio = rnd();
        left = right = NULL;
    }
    
    int ind;
    int val;

    int cnt;
    int sum_val;

    uint32_t prio;
    
    node* left;
    node* right;
};

int cnt(node* a) {
    if (a == NULL)
        return 0;
    return a->cnt;
}

int sum_val(node* a) {
    if (a == NULL)
        return 0;
    return a->sum_val;
}

void recalc(node* a) {
    a->cnt = cnt(a->left) + 1 + cnt(a->right);

    a->sum_val = sum_val(a->left) + a->val + sum_val(a->right);
}

pair<node*, node*> split_val(node* a, int ind) {
    if (a == NULL)
        return make_pair<node*, node*>(NULL, NULL);

    if (a->ind < ind) {
        auto spl = split_val(a->right, ind);
        a->right = spl.first;
        recalc(a);
        
        return make_pair(a, spl.second);
    } else {
        auto spl = split_val(a->left, ind);
        a->left = spl.second;
        recalc(a);

        return make_pair(spl.first, a);
    }
}

pair<node*, node*> split(node* a, int k) {
    if (a == NULL)
        return make_pair<node*,node*>(NULL, NULL);

    if (cnt(a->left) >= k) {
        auto spl = split(a->left, k);
        a->left = spl.second;

        recalc(a);
        return make_pair(spl.first, a);
    } else {
        auto spl = split(a->right, k - 1 - cnt(a->left));
        a->right = spl.first;

        recalc(a);
        return make_pair(a, spl.second);
    }
}

node* merge(node* a, node* b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->prio > b->prio) {
        a->right = merge(a->right, b);
        recalc(a);
        return a;
    } else {
        b->left = merge(a, b->left);
        recalc(b);
        return b;
    }
}


void solve() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<int> p(n);
    input_seq(ALL(p));

    vector<int> ind(n);
    std::iota(ALL(ind), 0);

    std::sort(ALL(ind), [&](int i, int j) {
            return p[i] < p[j];
        });

    int ans = 0;
    int dval = 1;

    node* tree = NULL;

    auto ok = [&](int val) {
        int full = (val == 0 ? 0 : (val % m == 0 ? val / m - 1 : val / m));
        auto spl = split(tree, full * m);

        if (2 * sum_val(spl.first) > t) {
            tree = merge(spl.first, spl.second);
            return false;
        }

        auto spl2 = split(spl.second, val - full * m);
        bool res =  (2 * sum_val(spl.first) + sum_val(spl2.first) <= t);

        spl.second = merge(spl2.first, spl2.second);
        tree = merge(spl.first, spl.second);

        return res;
    };
    
    for (int i = 0; i < SZ(ind);) {
        int i0 = i;

        for (; i < SZ(ind) and p[ind[i]] == p[ind[i0]]; ++i) {
            auto spl = split_val(tree, ind[i]);
            tree = merge(spl.first, merge(new node(ind[i], p[ind[i]]), spl.second));
        }
        
        int lo = ans; // MAYBE CAN
        int hi = i + 1; // CAN NOT

        while (hi - lo > 1) {
            int mi = lo + (hi - lo) / 2;
            if (ok(mi))
                lo = mi;
            else
                hi = mi;
        }

        if (lo > ans)
            ans = lo, dval = p[ind[i0]];
    }

    cout << ans << " " << dval << "\n";
}

int32_t main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int tc = input<int>(); tc != 0; --tc) {
        solve();
    }
    
    return 0;
}