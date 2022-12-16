// 10:20
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Segtree {
    vector<int> t;
    int n, h;
    Segtree(int sz) {
        h = 32-__builtin_clz(sz);
        n = 1<<h;
        t = vector<int>(n<<1, 0);
    }
    void add(int x, int v) {
        for (x+=n; x; x/=2) {
            t[x] += v;
        }
    }
    int query(int l, int r) {
        int ans = 0;
        for (l+=n, r+=n;l<r; l/=2, r/=2) {
            if (l%2) ans += t[l++];
            if (r%2) ans += t[--r];
        }
        return ans;
    }
};

struct Query {
    int l, r, ind;
    bool operator< (const Query& o) const {
        return r < o.r;
    }
};

const int N = 200200;
int a[N], rev[N];
vector<int> facs[N];

void setup() {
    for (int i=1; i<N; ++i) {
        for (int j=i; j<N; j+=i) {
            if (rev[i] < rev[j]) {
                facs[rev[j]].push_back(rev[i]);
            } else {
                facs[rev[i]].push_back(rev[j]);
            }
        }
    }
}

int n, m;

int ans[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        rev[a[i]] = i;
    }
    setup();
    vector<Query> queries;
    for (int i=1; i<=m; ++i) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }
    sort(queries.begin(), queries.end());

    Segtree segtree(n+5);
    int prev = 0;

    for (auto& q : queries) {
        while (prev < q.r) {
            ++prev;
            for (auto& x : facs[prev]) {
                segtree.add(x, 1);
            }
        }
        ans[q.ind] = segtree.query(q.l, q.r+1);

    }
    for (int i=1; i<=m; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}