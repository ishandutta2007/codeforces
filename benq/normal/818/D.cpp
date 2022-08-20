/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
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

int num[100001];
int n,A; 
vi col[1000001];

bool ok(int c) {
	if (c == A) return 0;
	F0R(i,col[c].size()) if (num[col[c][i]-1] > i) return 0;
	if (num[n] > (int)col[c].size()) return 0;
	return 1;
}

int main() {
	cin >> n >> A; 
	FOR(i,1,n+1) {
		int x; cin >> x;
		num[i] = num[i-1];
		if (x == A) num[i] ++;
		else col[x].pb(i);
	}
	FOR(i,1,1000001) if (ok(i)) {
		cout << i;
		return 0;
	}
	cout << -1;
}