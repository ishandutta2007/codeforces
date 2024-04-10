#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<ll,ll> pll;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n;
vector<pll> p, P, totest;
set<pll> z;
ll ans = 0;
pll sum;

pll operator+ (const pll& l, const pll& r) {
    return {l.f+r.f,l.s+r.s};
}

pll operator- (const pll& l, const pll& r) {
    return {l.f-r.f,l.s-r.s};
}

void process(pll x) {
    if (x.f == 0 && x.s == 0) return;
    ll g = __gcd(x.f,x.s);
    x.f /= g, x.s /= g;
    if (x.f < 0 || (x.f == 0 && x.s < 0)) x.f *= -1, x.s *= -1;
    totest.pb(x);
}

void test(pll t) {
    vector<ll> cur;
    for (auto a: P) cur.pb((ll)a.f*t.s-(ll)a.s*t.f);
    sort(cur.begin(),cur.end());
    F0R(i,cur.size()) if (cur[i] != -cur[cur.size()-1-i]) return;
    ans++;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; p.resize(n);
	F0R(i,n) {
	    cin >> p[i].f >> p[i].s;
	    sum = sum+p[i];
	    p[i].f *= n, p[i].s *= n;
	}
	F0R(i,n) {
	    p[i] = p[i]-sum;
	    if (z.count(mp(-p[i].f,-p[i].s))) z.erase(mp(-p[i].f,-p[i].s));
	    else z.insert(p[i]);
	}
	for (auto a: z) P.pb(a);
	if (P.size() <= 1) {
	    cout << -1;
	    return 0;
	}
    F0R(i,P.size()) FOR(j,i,P.size()) process(P[i]+P[j]);
    sort(totest.begin(),totest.end());
    F0R(i,totest.size()) {
        int i1 = i;
        while (i < totest.size() && totest[i] == totest[i1]) i++;
        if (2*(i-i1+1) >= P.size()) test(totest[i1]);
    }
    cout << ans;
}

// read!
// ll vs. int!