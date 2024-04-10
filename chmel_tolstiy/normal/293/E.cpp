#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int nn = 1 << 17;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<int> vi;

long long ans;
int n, L, W;
vp g[nn];
vi u;
vi sz;

int size(int x, int p) {
    if (u[x]) return 0;
    sz[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
        if (g[x][i].first != p) sz[x] += size(g[x][i].first, x);
    return sz[x];
}

int find(int x, int p, int n) {
    for (int i = 0; i < g[x].size(); ++i) {
        if (g[x][i].first != p && sz[g[x][i].first] > n / 2 && u[g[x][i].first] == 0)
            return find(g[x][i].first, x, n);
    }
    return x;
}

void dist(int s, int p, int d, int l, vp& c) {
    c.push_back(pii(l, d));
    for (int i = 0; i < g[s].size(); ++i) if (u[g[s][i].first] == 0 && g[s][i].first != p)
        dist(g[s][i].first, s, d + g[s][i].second, l + 1, c);
}

class sum {
    vi w;
    vi s;
public:
    sum(const vi& _w): w(_w) {
        int n = w.size();
        sort(w.begin(), w.end());
        w.resize(unique(w.begin(), w.end()) - w.begin());
        s.resize(w.size() + 1);
    }

    void add(int x) {
        int pos = lower_bound(w.begin(), w.end(), x) - w.begin();
        ++pos;
        while (pos < s.size()) {
            s[pos]++; pos = pos * 2 - (pos & (pos - 1));
        }
    }

    int get(int x) {
        int pos = lower_bound(w.begin(), w.end(), x) - w.begin();
        ++pos;
        int res = 0;
        while (pos) {
            res += s[pos]; pos &= pos - 1;
        }
        return res;
    }
};

vp merge(vp& l, vp& r) {
    vi w;
    for (int i = 0; i < l.size(); ++i) w.push_back(l[i].second);
    for (int i = 0; i < r.size(); ++i) w.push_back(W - r[i].second);
    sum s(w);

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    int j = 0;
    for (int i = r.size() - 1; i >= 0; --i) {
        while (j < l.size() && l[j].first + r[i].first <= L) {
            s.add(l[j].second);
            ++j;
        }
        ans += s.get(W - r[i].second);
    }
    for (int i = 0; i < r.size(); ++i) l.push_back(r[i]);
    return l;
}

vp dfs(int s) {
    size(s, -1);
    int x = find(s, -1, sz[s]);
    vp r;
    dist(s, -1, 0, 0, r);
    u[x] = 1;
    vector<vp> m;
    for (int i = 0; i < g[x].size(); ++i) if (u[g[x][i].first] == 0) {
        vp r = dfs(g[x][i].first);
        for (int j = 0; j < r.size(); ++j) {
            r[j].first += 1;
            r[j].second += g[x][i].second;

            if (r[j].first <= L && r[j].second <= W) ++ans;
        }
        m.push_back(r);
    }


    for (int i = 0; i + 1 < m.size(); i += 2) {
        m.push_back(merge(m[i], m[i+1]));
    }

    return r;
}

int main() {
    cin >> n >> L >> W;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        x = i + 1;
        cin >> y >> z; --y;
        g[x].push_back(pii(y, z));
        g[y].push_back(pii(x, z));
    }

    u.assign(n, 0);
    sz.assign(n, 0);
    size(0, -1);
    dfs(0);

    cout << ans << endl;
    return 0;
}