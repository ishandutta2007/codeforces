#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;



const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const int N = int(2e5) + 99;

int n;
vector <int> v[N];

bool read() {
    if(!(cin >> n))
        return false;
    forn(i, n) {
        int s;
        cin >> s;
        v[i].resize(s);
        forn(j, s) cin >> v[i][j];
        sort(all(v[i]));
    }
    return true;
}

void solve() {
    int mx = v[0][0];
    forn(i, n) mx = max(mx, v[i].back());
    li res = 0;
    forn(i, n) res += sz(v[i]) * 1LL * (mx - v[i].back());

    cout << res << endl;
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