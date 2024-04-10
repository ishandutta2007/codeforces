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

const int MOD = 1000000007;

const ll INF = 1LL<<60;

int n;
string s;
ll ans = INF;
vi tmp;
ll dp[1<<14];

void test(vi tmp1) {
    int sum = 0;
    F0R(i,tmp1.size()) sum += tmp1[i];
    if (sum != 0) return;
    
    F0R(i,1<<n) dp[i] = INF;
    dp[0] = 0;
    
    F0R(i,1<<n) if (dp[i] != INF) {
        if (i == 0) {
            F0R(j,n) dp[1<<j] = dp[i];
        } else {
            ll csum = 0; F0R(j,n) if (i&(1<<j)) csum += tmp1[j];
            if (csum < 0 || csum > 15) continue;
            F0R(j,n) if (!(i&(1<<j))) {
                ll x = dp[i] | (csum<<(4*(n-1-j)));
                dp[i^(1<<j)] = min(dp[i^(1<<j)],x);
            }
        }
    }
    ans = min(ans,dp[(1<<n)-1]);
}

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s; 
	n = s.length();
	tmp.resize(n);
	F0R(i,n) {
	    if ('0' <= s[i] && s[i] <= '9') tmp[i] = int(s[i]-'0');
	    else tmp[i] = 10+int(s[i]-'a');
	}
}

int main() {
	init();
	F0R(i,1<<(n-1)) {
	    vi tmp1 = tmp;
	    F0R(j,n) if (i&(1<<j)) {
	        tmp1[j] ++;
	        tmp1[j+1] -= 16;
	    }
	    test(tmp1);
	}
	if (ans != INF) {
	    F0R(i,n) {
	        ll tmp = (ans>>(4*(n-1-i))) % 16;
	        if (tmp <= 9) cout << tmp;
	        else cout << char('a'+int(tmp-10));
	    }
	}
	else cout << "NO";
}

// read!
// ll vs. int!