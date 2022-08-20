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
const int MX = 1000001;

int n, q;
ll ans;
set<pii> cur;

int mag(pii x) {
    return x.s-x.f+1;
}

void rem(int a, int b) {
    while (1) {
        auto it = cur.lb({a,-MOD});
        if (it == cur.end() || it->f > b) break;
        int B = it->s;
        ans -= mag(*it); cur.erase(it); 
        if (B > b) {
            cur.insert({b+1,B});
            ans += B-b;
        }
    }
    
    auto it = cur.lb({a,-MOD});
    if (it == cur.begin()) return;
    it = prev(it);
    if (it->s < a) return;
    else if (it->s > b) {
        int A = it->f, B = it->s;
        ans -= mag(*it);
        cur.erase(it);
        cur.insert({A,a-1});
        cur.insert({b+1,B});
        ans += a-A;
        ans += B-b;
    } else {
        int A = it->f;
        ans -= mag(*it);
        cur.erase(it);
        cur.insert({A,a-1});
        ans += a-A;
    }
}

void upd(int a, int b, int c) {
    rem(a,b);
    if (c == 2) {
        ans += b-a+1;
        cur.insert({a,b});
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	cur.insert({1,n});
	ans = n;
	F0R(i,q) {
	    int a,b,c; cin >> a >> b >> c;
	    upd(a,b,c);
	    cout << ans << "\n";
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!