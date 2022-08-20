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

int k,t, num = 1;
map<vi,int> dp;

char con(int x) {
    if (x <= 9) return char('0'+x);
    return char('a'+(x-10));
}

int sum(vi& z) {
    int su = 0;
    F0R(i,z.size()) su += z[i];
    return su;
}

ll solve(vi z) {
    if (z.back() > t) return 0;
    if (sum(z) == num) return 1;
    if (dp.count(z)) return dp[z];
    ll tmp = 0;
    for (int i = 0; i < z.size();) {
        int i1 = i;
        while (i < z.size() && z[i] == z[i1]) i++;
        
        z[i-1] ++;
        tmp += (i-i1)*solve(z);
        z[i-1] --;
    }
    return dp[z] = tmp;
}

ll solve1(vi z) {
    sort(z.begin(),z.end());
    return solve(z);
}

ll get() { // certain number of digits
    dp.clear();
    vi z(16); z[15] = 1;
    return 15*solve(z);
}

vi oc(16);

string fin(int lef) {
    string ans;
    F0R(i,lef) {
        F0R(j,16) {
            oc[j] ++;
            if (solve1(oc) < k) {
                k -= solve1(oc);
                oc[j] --;
            } else {
                ans += con(j);
                break;
            }
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> k >> t;
	while (1) {
	    ll x = get();
	    // cout << x << "\n";
	    if (k > x) k -= x, num++;
	    else break;
	}
	ll x = get()/15;
	
	int beg = 1;
	while (x < k) {
	    k -= x;
	    beg++;
	}
	oc[beg] ++;
	dp.clear();
	cout << con(beg)+fin(num-1);
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!