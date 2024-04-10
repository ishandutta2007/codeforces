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

int m,d, cmod;
string a,b;
int pre[2001][2000], po10[2001];
int z = 0;

void gen(string& x) {
	po10[0] = 1;
	FOR(i,1,2001) po10[i] = 10*po10[i-1] % m;
	memset(pre,0,sizeof pre);
	
	pre[x.length()][0] = 1;
    FORd(i,1,x.length()) {
        F0R(j,m) {
			if (i % 2 == 0) {
				F0R(k,10) if (k != d) {
					int tmp = (po10[x.length()-1-i]*k+j) % m;
					pre[i][tmp] = (pre[i][tmp]+pre[i+1][j]) % MOD;
				}
			} else {
				int tmp = (po10[x.length()-1-i]*d+j) % m;
				pre[i][tmp] = (pre[i][tmp]+pre[i+1][j]) % MOD;
			}
        }
    }
}

ll g(string x) {
	gen(x);
    int tmp = 0; cmod = 0;
    F0R(i,x.length()) {
        F0R(j,int(x[i]-'0')) if ((i % 2 == 0 && j != d) || (i % 2 == 1 && j == d)) {
        	int cmod2 = -(cmod+po10[x.length()-1-i]*j) % m;
        	cmod2 = (cmod2+m) % m;
        	tmp = (tmp+pre[i+1][cmod2]) % MOD;
        }
        if (i % 2 == 0) {
        	if (x[i] == char('0'+d)) break;
        } else if (x[i] != char('0'+d)) break;
        
        cmod = (cmod+po10[x.length()-1-i]*(x[i]-'0')) % m;
        if (i == x.length()-1 && cmod == 0) tmp++;
    }
    return tmp;
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> m >> d >> a >> b;
	
	a[a.length()-1] --;
	F0Rd(i,a.length()) if (a[i] < '0') {
		a[i] += 10;
		a[i-1] --;
	}
}

int main() {
	init();
	ll ans = g(b)-g(a);
	ans = (ans+MOD) % MOD;
	cout << ans;
}

// read!
// ll vs. int!