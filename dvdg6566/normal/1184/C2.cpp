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

struct node {
    int v,lz;
    node *l, *r;
    node(int s, int e): v(0), lz(0) {
        int m = (s+e)/2;
        if (s != e) {
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    int val(int s, int e) {
        if (s != e) {
            l->lz += lz;
            r->lz += lz;
        }
        v += lz; lz = 0;
        return v;
    }

    void add(int s, int e, int x, int y, int z) {
        assert(s <= e and s >= 0 and e <= (int)4e6 and x >= 0 and y <= (int)4e6);
        int m = (s+e)/2;
        //cout << s << " " << e << " :: " << m << " :: " << x << " " << y << " z " << z << endl;
        if (s == x && e == y) { lz += z; return; }
        else if (y <= m) l->add(s,m,x,y,z);
        else if (x >  m) r->add(m+1,e,x,y,z);
        else l->add(s,m,x,m,z), r->add(m+1,e,m+1,y,z);
        v = max(l->val(s,m), r->val(m+1,e));
    }
} *root;

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,r;
    cin >> n >> r;
    ii p[n];
    FOR(i,0,n-1){
        cin >> p[i].fi >> p[i].sc;
        p[i].fi += 1e6;
        p[i].sc += 1e6;
    }

    const int G = (int)2e6;
    sort(p, p+n, [](ii a, ii b){ return (a.fi-a.sc) < (b.fi-b.sc); });
    root = new node(0,2*G);
    int s = 0, e = 0, ans = 0;
    for(; e < n; ++e) {
        //sum(p[e].fi+p[e].sc, p[e].fi+p[e].sc + 2*r);
        root->add(0, 2*G, max(0,p[e].fi+p[e].sc-2*r), p[e].fi+p[e].sc, 1);

        while ((p[e].fi-p[e].sc) - (p[s].fi-p[s].sc) > 2*r) { 
            root->add(0, 2*G, max(0,p[s].fi+p[s].sc-2*r), p[s].fi+p[s].sc, -1);
            ++s;
        }

        ans = max(ans, root->val(0,2*G));
    }
    cout << ans << '\n';
}