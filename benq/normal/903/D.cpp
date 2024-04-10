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

int n;
ll a[200000];
ll ans = 0;
ll sum = 0, sum8 = 0;
map<int,int> m;

const ll INF = 1e18;

void normalize() {
	while (ans >= INF) {
        ans -= INF;
        sum8 ++;
    }
    while (ans < 0) {
        ans += INF;
        sum8 --;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    cin >> a[i];
	    //if (i >= 100000) a[i] = 1;
	    //else a[i] = 999999999;
	    m[a[i]] ++;
	    sum += a[i];
	}
	F0R(i,n) {
	    ll NUM = n-i, SUM = sum;
	    NUM -= m[a[i]]; SUM -= m[a[i]]*a[i];
	    NUM -= m[a[i]-1]; SUM -= m[a[i]-1]*(a[i]-1);
	    NUM -= m[a[i]+1]; SUM -= m[a[i]+1]*(a[i]+1);
	    ans += SUM-NUM*a[i];
	    
	    m[a[i]] --; sum -= a[i];
	    normalize();
	}
	
	if (sum8 < 0) {
	    cout << "-";
	    sum8 *= -1, ans *= -1;
	} 
	normalize();
	if (sum8) {
	    cout << sum8;
	    string t = to_string(ans);
	    while (sz(t) < 18) t = '0'+t;
	    cout << t;
	} else cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!