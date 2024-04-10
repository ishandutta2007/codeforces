#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
#define int long long
using BIG = long double;

struct Frac {
    int a, b;
    Frac(int up, int dw) : a(up), b(dw) {
        if (b < 0) {
            a = -a;
            b = -b;
        }
    }
    int CompareTo(Frac oth) {
        BIG x = a; x *= oth.b;
        BIG y = b; y *= oth.a;
        if (abs(x - y) < 1.0e-2L) return 0;
        if (x < y) return -1;
        if (x > y) return 1;
        assert(false);
    }
    Frac operator*(int x) {
        return Frac{a * x, b}; 
    }
    Frac operator+(Frac oth) {
        int up = a * oth.b + oth.a * b;
        int dw = b * oth.b;
        return {up, dw};
    }
};

struct Line {
    Frac slope, intercept;
    int idx, mapped, lo;

    Frac Eval(int x) {
        return slope * x + intercept;
    }
};

struct Fenwick {
    vector<int> T;

    Fenwick(int n) : T(n + 1, 0) {}

    void Add(int pos) {
        //cerr << "ADD: " << pos << endl;
        for (++pos; pos < (int)T.size(); pos += (pos & -pos))
            T[pos] += 1;
    }

    void Clear() { 
        //cerr << "CLEAR" << endl;
        fill(T.begin(), T.end(), 0); 
    }

    int query(int pos) {
        int ans = 0;
        for (; pos > 0; pos -= (pos & -pos))
            ans += T[pos];
        return ans;
    }
    int Query(int b, int e) {
        //cerr << "QUERY: " << b << " " << e << endl;
        int ret = query(e) - query(b);
        //cerr << "---> " << ret << endl;
        return ret;
    }
};

ostream& operator<<(ostream& out, Frac f) {
    out << f.a << "/" << f.b;
    return out;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, w; cin >> n >> w;
    vector<Line> lines;
    for (int i = 0; i < n; ++i) {
        int x, v; cin >> x >> v;
        lines.push_back(Line{Frac{1, x}, Frac{v, x}, i, -1, -1});
    }
/*
    for (auto x : lines) {
        cerr << x.slope << "X + " << x.intercept << endl;
        cerr << "EVAL AT -W: " << x.Eval(-w) << endl;
        cerr << "EVAL AT +W: " << x.Eval(+w) << endl;
    }
  */      
    int eval_value;
    auto eval = [&](Line a) { return a.Eval(eval_value); };
    auto cmp = [&](Line a, Line b) {
        return eval(a).CompareTo(eval(b)) < 0; 
    };

    eval_value = w;
    sort(lines.begin(), lines.end(), cmp);
    /*
    cerr << "+W ORDER: " << endl;
    for (auto x : lines) cerr << x.idx << " "; cerr << endl;
    */
    int l;
    Fenwick fw(n);

    long long ans = 0;

    l = 0;
    while (l < n) {
        int r = l;
        while (r < n && eval(lines[l]).CompareTo(eval(lines[r])) == 0) ++r;
        for (int i = l; i < r; ++i) {
            lines[i].mapped = i;
            lines[i].lo = r;
        }
        ans += 1LL * (r - l) * (r - l - 1) / 2;
        l = r;
    }
    
    if (w == 0) {
        cout << ans << endl;
        return 0;
    }    

    // cerr << "ANS 1: " << ans << endl;    
    eval_value = -w;
    sort(lines.begin(), lines.end(), cmp);
    
    // cerr << "-W ORDER: " << endl;
    // for (auto x : lines) cerr << x.idx << " "; cerr << endl;
    
    l = 0;
    while (l < n) {
        int r = l;
        while (r < n && eval(lines[l]).CompareTo(eval(lines[r])) == 0) ++r;
        for (int i = l; i < r; ++i) {
            ans += fw.Query(lines[i].lo, n);
        }
        for (int i = l; i < r; ++i) {
            fw.Add(lines[i].mapped);    
        }

        ans += 1LL * (r - l) * (r - l - 1) / 2;
        l = r;
    }

    // cerr << "ANS 2: " << ans << endl;

    cout << ans << endl;

    return 0;
}