#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

set<string> names;
vector<string> in;

string getname() {
	while (1) {
		string z;
		z += (rand() % 26) + 'A';
		F0R(i,9) z += (rand() % 26) + 'a';
		if (names.find(z) == names.end()) {
			names.insert(z);
			return z;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k; cin >> n >> k; in.resize(n);
	F0R(i,n-k+1) cin >> in[i];
	vector<string> ans;
	F0R(i,k-1) ans.pb(getname());
	FOR(i,k,n+1) {
		if (in[i-k] == "YES") {
			ans.pb(getname());
		} else {
			ans.pb(ans[i-k]);
		}
	}
	for (auto a: ans) cout << a << " ";
}