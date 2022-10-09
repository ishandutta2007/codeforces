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


int n, m;
set <pt> s;

bool read() {
    if(!(cin >> n >> m))
        return false;
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if(x > y) swap(x, y);
        s.insert(mp(x, y));
    }
    return true;
}

void solve() {
    if(n * 1LL * (n - 1) / 2 == sz(s)){
        cout << "NO" << endl;
        return;
    }

    forn(i, n) forn(j, i)
        if(!s.count(mp(j, i))){
            vector <int> v(n);
            int cur = n;
            v[i] = cur--;
            v[j] = cur--;
            forn(k, n) if(v[k] == 0) v[k] = cur--;

            cout << "YES" << endl;
            forn(i, n) cout << v[i] << ' ';
            cout << endl;
            v[i] = v[j] = n;
            forn(i, n) cout << v[i] << ' ';
            cout << endl;
            return;
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