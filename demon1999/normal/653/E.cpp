#include <bits/stdc++.h>
#define forn(i, n) for(ll i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef double ld;
using namespace std;

struct T { int x, y; };
T t = {1, 2};
const int ma = 2 * 131072;

int n, m, k, qq = 0, a, b, kk[300000];
set<int> q;

set<pair<int, int> > edge;
bool ok(int a, int b) {
    if (edge.find(mp(a, b)) != edge.end()) re false;
    else re true;
}

void dfs(int nu) {
    vector<int> p;
    qq++;
    for (int v : q) {
        if (ok(nu, v)) p.push_back(v);
    }
    for (int v : p)
        q.erase(v);
    for (int v : p)
        dfs(v);
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qqq.in", "r",  stdin));
    cin >> n >> m >> k;
    forn (i, m) {
        cin >> a >> b;
        a--;
        b--;
        kk[a]++;
        kk[b]++;
        edge.insert(mp(a, b));
        edge.insert(mp(b, a));
    }
    if (n - kk[0] - 1 < k) {
        cout << "impossible";
        re 0;
    }
    forn (i, n) q.insert(i);
    q.erase(0);
    dfs(0);
    if (qq < n) {
        cout << "impossible\n";
        re 0;
    }
    forn (i, n) q.insert(i);
    q.erase(0);
    while (!q.empty()) {
        qq = 0;
        dfs(*q.begin());
        k--;
    }
    if (k < 0) cout << "impossible\n";
    else cout << "possible";
    return 0;
}