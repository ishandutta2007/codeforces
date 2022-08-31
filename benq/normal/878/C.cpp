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

int q = 0;

bool z(vi x, vi y) {
	F0R(i,x.size()) if (x[i] >= y[i]) return 0;
	return 1;
}

struct pa {
	mutable int co;
	mutable vi f, s;
	bool operator<(const pa& r) const {
		if (q == 0) return mp(f,s)<mp(r.f,r.s);
		if (q == 1) return z(s,r.s);
		return !z(r.f,f);
	}
	pa(int CO, vi F, vi S) {
	    co = CO, f = F, s = S;
	}
	void print() {
	    cout << co << " | ";
	    for (int i: f) cout << i << " ";
	    cout << "| ";
	    for (int i: s) cout << i << " ";
	    cout << "\n";
	}
};

vi combmx(vi x, vi y) {
    F0R(i,x.size()) x[i] = max(x[i],y[i]);
    return x;
}

vi combmn(vi x, vi y) {
    F0R(i,x.size()) x[i] = min(x[i],y[i]);
    return x;
}

int n,k;
set<pa> S;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) {
	    vi a(k); F0R(j,k) cin >> a[j];
	    
	    q = 1; auto it = S.lb(pa(0,{},a)); q = 0;
	    while (it != S.end()) {
	        if (z(a,it->f)) break; 
	        it->s = combmx(it->s,a);
	        if (it != S.begin() && !z(prev(it)->s,it->f)) {
	            it->f = combmn(prev(it)->f,it->f);
	            it->co += prev(it)->co;
	            S.erase(prev(it));
	        }
	        it = next(it);
	    }
	    
	    q = 2; it = S.lb(pa(0,a,{})); q = 0; // last it such that z(a,it) = 0
	    // lower bound: first one such that !z(a,it) = 0
	    
	    if (it == S.begin() || z(prev(it)->s,a)) S.insert(pa(1,a,a));
	    else {
	        it = prev(it);
	        it->f = combmn(it->f,a);
	        it->co ++;
	    }
	    
	    //if (i == 5) cout << "OOPS\n";
	    cout << S.rbegin()->co << "\n";
	    //for (auto a: S) a.print();
	    //cout << "-----\n";
	     //last one such that !(it < a) 
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!