#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define puts sykk
//#define endl '\n'

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
const int N = int(1e5) + 99;

struct box{
    int id;
    int need;
    set <int> s;
};

int n, tp;
box b[N];

bool read() {
    if(!(cin >> n >> tp))
        return false;
    forn(i, n){
        b[i].id = i;
        int s;
        cin >> s;
        forn(j, s){
            int x;
            cin >> x;
            b[i].s.insert(x);
        }
    }
    return true;
}


bool cmp(const box &a, const box &b){
    if(sz(a.s) != sz(b.s))
        return sz(a.s) < sz(b.s);
    return a.id < b.id;
}

map<int, vector <int> > m;

void solve() {
    sort(b, b + n, cmp);

    int sum = 0;
    forn(i, n)
    sum += sz(b[i].s);

    forn(i, n)
        b[i].need = sum / n;
    int cnt = sum % n;
    for(int i = n - 1; i >= 0, cnt > 0; --i, --cnt)
            ++b[i].need;

    forn(i, 0){
        cout << b[i].id << ' ' << b[i].need << endl;
        for(auto x : b[i].s) cout << x << ' ';
        cout << endl;
    }

    // s -> t
    set <int> s, t;
    forn(i, n){
        if(sz(b[i].s) > b[i].need)
            s.insert(i);
        if(sz(b[i].s) < b[i].need)
            t.insert(i);
    }

    //cout << vector <int> (all(s)) << endl;
    //cout << vector <int> (all(t)) << endl;
    forn(i, n) for(auto x : b[i].s) m[x].pb(i);

    vector <vector <int> > ans;
    for(auto p : m){
        set <int> u(all(p.y));

        vector <int> ds, dt;
        auto its = s.begin();
        auto itt = t.begin();

        while(true) {
            while(its != s.end() && !u.count(*its)) ++its;
            while(itt != t.end() && u.count(*itt)) ++itt;

            if(itt == t.end() || its == s.end()) break;
            //cout << p.x << ' ' << *its << ' ' << *itt << endl;
            int X = p.x;
            ans.pb({b[*its].id + 1, b[*itt].id + 1, X});
            b[*its].s.erase(X);
            b[*itt].s.insert(X);
            u.erase(*its);
            u.insert(*itt);
            if(sz(b[*its].s) == b[*its].need) ds.pb(*its);
            if(sz(b[*itt].s) == b[*itt].need) dt.pb(*itt);
        }

        for(auto x : ds) s.erase(x);
        for(auto x : dt) t.erase(x);
    }

    cout << sz(ans) << endl;
    for(auto v : ans){
        for(auto x : v) cout << x << ' ';
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
//cout << 'a' << endl;
    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
#endif
    }
    return 0;
}