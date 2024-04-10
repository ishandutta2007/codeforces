#include <bits/stdc++.h>

using namespace std;

struct Frac {
    long long a = 0, b = 1;
    int idx, typ;

    Frac() {}
    Frac(long long a, long long b, int idx, int typ)
        : a(a), b(b), idx(idx), typ(typ) {}

    bool operator< (const Frac& oth) const {
        long double x = a; x *= oth.b;
        long double y = b; y *= oth.a;
        return x < y;
    }
};

int main() {
    int k, n, m; 
    cin >> k >> n >> m;
    
    vector<int> initial(k);
    vector<Frac> assign(k);
    vector<vector<Frac>> add(k);
    vector<Frac> mul;

    for (int i = 0; i < k; ++i) {
        cin >> initial[i];
    }

    for (int i = 0; i < n; ++i) {
        int t, pos, val; 
        cin >> t >> pos >> val;
        --pos;

        if (t == 1) assign[pos] = max(assign[pos], Frac{val, 1, i, 1});
        if (t == 2) add[pos].push_back(Frac{val, 1, i, 2});
        if (t == 3) mul.push_back(Frac{val, 1, i, 3});
    }

    cerr << "Done reading" << endl;

    for (int i = 0; i < k; ++i) {
        if (assign[i].a > initial[i]) {
            add[i].push_back(Frac{assign[i].a - initial[i], 
                    1, assign[i].idx, 1});
        }
    }

    cerr << "Done transforming assign -> add" << endl;

    for (int i = 0; i < k; ++i) {
        long long now = initial[i]; 
        sort(add[i].rbegin(), add[i].rend());
        for (auto x : add[i]) {
            mul.push_back(Frac{now + x.a, now, x.idx, x.typ});
            now += x.a;
        }
    }

    cerr << "Done tranforming add -> mul" << endl;

    sort(mul.rbegin(), mul.rend());

    int ans = min(m, (int)mul.size());
    vector<pair<int, int>> ret;

    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        ret.emplace_back(mul[i].typ, mul[i].idx + 1);
    }
    sort(ret.begin(), ret.end());
    for (auto x : ret) cout << x.second << " ";
    cout << endl;
    
    return 0;
}