#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, m, k;
struct Ladder {
    int a, b, c, d, h, hp;
}; 
map<int, vector<Ladder>> start, endd;
vector <int> x;
Ladder first, last, l;

void pre() {
    cin >> n >> m >> k;
    x.resize(n);
    forn(i, 0, n) cin >> x[i];
    start.clear(); endd.clear();
    forn(i, 0, k) {
        cin >> l.a >> l.b >> l.c >> l.d >> l.h;
        --l.a; --l.b; --l.c; --l.d;
        l.hp = INF;
        start[l.a].push_back(l);
    }
    first.a = -1; first.b = -1; first.c = 0; first.d = 0; first.h = 0; first.hp = 0;
    endd[0].push_back(first);
    last.a = n - 1; last.b = m - 1; last.c = n; last.d = m; last.h = 0; last.hp = INF;
    start[n-1].push_back(last);
}

bool comp_inc(Ladder &A, Ladder &B) {
    return A.d < B.d;
}
bool comp_dec(Ladder &A, Ladder &B) {
    return A.d > B.d;
}

void solve() {
    pre();
    for(int i = 0; i < n; i++) {
        int sz = 0;
        vector <pair<int, int>> left;
        {
            left.push_back({-1, INF});
            sz++;
            sort(endd[i].begin(), endd[i].end(), comp_inc);
            for(auto j : endd[i]) {
                left.push_back({j.d, min(j.hp, left[sz-1].second + (j.d - left[sz-1].first)*x[i])});
                sz++;
            }
        }
        sz = 0;
        vector <pair<int, int>> right;
        {
            right.push_back({m, INF});
            sz++;
            sort(endd[i].begin(), endd[i].end(), comp_dec);
            for(auto j : endd[i]) {
                right.push_back({j.d, min(j.hp, right[sz-1].second + (right[sz-1].first - j.d)*x[i])});
                sz++;
            }
        }
        sort(right.begin(), right.end());
        for(auto j : start[i]) {
            pair<int, int> p = {j.b, -INF};
            pair<int, int> f = *(--upper_bound(left.begin(), left.end(), p));
            if(f.second < INF) j.hp = min(j.hp, f.second + (j.b - f.first)*x[i] - j.h);
            f = *(lower_bound(right.begin(), right.end(), p));
            if(f.second < INF) j.hp = min(j.hp, f.second + (f.first - j.b)*x[i] - j.h);
            endd[j.c].push_back(j);
        }
    }
    // forn(i, 0, n + 1) {
    //     for(auto j : endd[i]) {
    //         cout << j.a << " " << j.b << " " << j.c << " " << j.d << " " << j.h << " " << j.hp << endl;
    //     }
    // }
    // cout << endl;
    if(endd[n][0].hp >= INF) cout << "NO ESCAPE" << endl;
    else cout << endd[n][0].hp << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}