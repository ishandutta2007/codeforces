#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

struct Edge { int a, b, e, i; };

class UnionFind {
    private: vector<int> p,r;
    public:
             UnionFind(int n) { r.assign(n, 0); p.assign(n, 0); iota(ALL(p), 0); }
             int findset(int i) { return (p[i] == i) ? i : (p[i] = findset(p[i])); }
             bool unionset(int i, int j) {
                 int x = findset(i), y= findset(j);
                 if (x != y) {
                     if (r[x] > r[y]) p[y] = x;
                     else { p[x] = y; if (r[x] == r[y]) ++r[y]; }
                     return true;
                 } else return false;
             }
};
            

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<Edge> el;
    FOR(i,0,m-1){
        int a, b, e; cin >> a >> b >> e;
        el.push_back({a,b,e,i});
    }

    int lo = 0, hi = (int)1e9+1;
    while (lo < hi) {
        int mid = (lo+hi)/2;

        for (auto& e : el) if (e.i == 0) e.e = mid;
        sort(ALL(el), [](Edge a, Edge b){ if (a.e == b.e) return a.i < b.i; else return a.e < b.e; });
        UnionFind UF(n+1);
        bool used = 0;
        for (auto& e : el) {
            if (UF.unionset(e.a, e.b)) used |= (e.i == 0);
        }

        //cout << lo << " " << hi << " :: " << mid << " :: " << used << endl;
        if (used) lo = mid+1;
        else hi = mid;
    }
    cout << lo-1 << '\n';
}