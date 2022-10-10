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
const int N = int(1e6) + 99;

int n;
map<string, vector <int> > m;
string s[N];
string t[N];

bool read() {
    if(!(cin >> n))
        return false;
    forn(i, n) cin >> s[i] >> t[i];
    return true;
}

void solve() {
    forn(i, n){
        int msk = 0;
        for(auto c : t[i])
            msk |= 1 << (c - 'a');

        string ss = s[i];
        while(sz(ss) > 0 && ((msk >> (ss.back() - 'a')) & 1) )
            ss.pop_back();

        string res = "";
        forn(i, 26) if((msk >> i) & 1) res += char('a' + i);
        res += '#';
        res += ss;
        m[res].pb(i);
    }

    cout << sz(m) << endl;
    for(auto pp : m) {
        auto v = pp.y;
        cout << sz(v) << ' ';
        for(auto x : v) cout << x + 1 << ' ';
        cout << endl;
    }
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