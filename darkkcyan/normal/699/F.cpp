#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

#define ci complex<int>
#define cx real()
#define cy imag()

int n, m;
ve<ci> a, b;
void read() {
    scanf("%d%d", &n, &m);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        a[i] = ci(x, y);
    }

    b.resize(m);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        b[i] = ci(x, y);
    }
}

struct cmpci {
    bool operator()(const ci& u, const ci& v) {
        if (u.cx == v.cx) return u.cy < v.cy;
        return u.cx < v.cx;
    }
};

int curai;
bool cmpdst(int u, int v) { return abs(a[curai] - b[u]) < abs(a[curai] - b[v]); }
ci normvec(const ci& u) { return u / __gcd(abs(u.cx), abs(u.cy)); }
ve<map<ci, vi, cmpci> > d;
vi p;
void preprocess() {
    d.resize(n);
    p.resize(m); for (int i = 0; i < m; ++i) p[i] = i;
    for (int i = 0; i < n; ++i) {
        curai = i;
        sort(p.begin(), p.end(), cmpdst);
        for (int f = 0; f < m; ++f)
            d[i][normvec(a[i] - b[p[f]])].push_back(p[f]);
    }
}

bool ans;
list<int> pl;
vi done;
void process(int mask) {
    if (sz(pl) > __builtin_popcount(mask))
        return;
    if (sz(pl) == 0) {
        ans = 1;
        return;
    }
    for (int i = 0; i < sz(pl); ++i) {
        int u = pl.front(); pl.pop_front();
        for (int f = 0; f < n; ++f) {
            if (ans) continue;
            vi cnt = done;
            if (~(mask >> f) & 1) continue;
            vi& t = d[f][normvec(a[f] - b[u])];
            int g = 0;
            for (; g < sz(t) and t[g] != u; ++g)
                if (done[t[g]]++ == 0)
                    pl.push_back(t[g]);
            process(mask - (1 << f));
            while (g--)
                if (--done[t[g]] == 0)
                    pl.pop_back();
        }
        pl.push_back(u);
    }
}

int process() {
    done.resize(m);
    int res = 0;
    for (int i = 0; i < m; ++i) {
        pl.clear();
        pl.push_back(i);
        ans = 0;
        ++done[i];
        process((1 << n) - 1);
        --done[i];
//        if (ans) clog << i << endl;
        res += ans;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    preprocess();
    cout << process();

    return 0;
}