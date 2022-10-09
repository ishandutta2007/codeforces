#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define puts sykk
#define endl '\n'

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

string s, t;

bool read() {
    if(!(cin >> s >> t))
        return false;
    return true;
}

vector<int> zf(const string &s) {
    vector<int> z(sz(s), 0);
    for(int i = 1, l = -1, r = -1; i < sz(s); i++) {
        if(i < r)
            z[i] = min(z[i - l], r - i);

        while(i + z[i] < sz(s) && s[i + z[i]] == s[z[i]])
            z[i]++;

        if(i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

int len = 0;
set<pt> segs;

void split(int pos) {
    auto it = segs.lower_bound({pos + 1, -1});
    if(it == segs.begin()) return;
    it--;

    if(pos <= it->x || it->y <= pos)
        return;

    pt cur = *it;
    segs.erase(it);

    segs.insert({cur.x, pos});
    segs.insert({pos, cur.y});
}

void erase(const pt &s) {
//    cerr << s << endl;
    split(s.x);
    split(s.y);

    auto it = segs.lower_bound({s.x, -1});
    while(it != segs.end() && it->x < s.y) {
        len -= it->y - it->x;
        it = segs.erase(it);
    }
//    cerr << vector<pt>(all(segs)) << endl;
}

void solve() {
    auto zs = zf(t + "$" + s);
    vector<int> cnt(sz(t) + 1, 0);
//    cerr << zs << endl;
    fore(i, 1, sz(s))
        cnt[zs[sz(t) + 1 + i]]++;
    cnt[0]++;

    auto zt = zf(t);
    segs.insert({1, sz(t) + 1});
    len += sz(t);

    li ans = 0;
    forn(i, sz(t) + 1) {
//        cerr << i << " = " << len << " " << cnt[i] << endl;
        if(i > 0)
            erase({i + 1, i + zt[i] + 1});

        ans += len * li(cnt[i]);
    }
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
#endif
    }
    return 0;
}