#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 500001;

int n,k, hei[MX], mn[MX], dep[MX];
set<pii> oc, bes, mx[MX];
vi bad;

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) dep[i] = -1;
	F0R(i,n) cin >> hei[i];
	oc.insert({0,n});
	
	F0Rd(i,n) {
	    if (i+k+1 <= n) oc.erase({hei[i+k+1],i+k+1});
	    if (hei[i] <= oc.begin()->f) bad.pb(i);
	    else if (sz(oc) == 1 || hei[i] <= next(oc.begin())->f) dep[i] = oc.begin()->s;
	    mn[i] = oc.begin()->f+1;
	    oc.insert({hei[i],i});
	}
	
	reverse(all(bad));
	if (!sz(bad)) {
	    cout << "YES";
	    exit(0);
	}
}

void ins(pii x) {
    bes.insert(x);
    auto it = bes.find(x);
    if (it->s <= next(it)->s) { bes.erase(it); return; }
    while (it != bes.begin() && prev(it)->s <= it->s) bes.erase(prev(it));
}

void solve() {
    // for (int i: bad) cout << i << "\n";
    int lo = bad.back(), hi = min(bad.front()+k,n-1);
    FOR(i,lo,n) if (dep[i] != -1) {
        mx[dep[i]].insert({hei[i]-1,i});
        // cout << i << " " << dep[i] << "\n";
    }
    FOR(i,lo,n) {
        mx[i].insert({MOD,0});
        if (i > hi && hei[i] < hei[bad.front()]) ins({mx[i].begin()->f,hei[i]});
    }
    // cout << bad.front() << " " <<
    FOR(i,lo,hi+1) {
        auto it = bes.lb({hei[i],mn[i]});
        if (it != bes.end() && mn[i] <= it->s) {
            //cout << i << " " << hei[i] << " " << mn[i] << "\n";
            //cout << it->f << " " << it->s << "\n";
            cout << "YES";
            exit(0);
        }
        if (dep[i] != -1 && dep[i] > hi && hei[dep[i]] < hei[bad.front()]) {
            mx[dep[i]].erase({hei[i]-1,i});
            ins({mx[dep[i]].begin()->f,hei[dep[i]]});
        }
    }
}

int main() { // answer NO
	init();
	solve();
	cout << "NO";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!