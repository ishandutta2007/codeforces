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

char grid[8][8];
pii c1[8], c2[8];
int t1 = MOD, t2 = MOD;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	F0R(i,8) c1[i] = c2[i] = {MOD,-MOD};
	F0R(i,8) F0R(j,8) {
	    cin >> grid[i][j];
	    if (grid[i][j] == 'W') {
	        c1[j].f = min(c1[j].f,i);
	        c1[j].s = max(c1[j].s,i);
	    } 
	    if (grid[i][j] == 'B') {
	        c2[j].f = min(c2[j].f,i);
	        c2[j].s = max(c2[j].s,i);
	    } 
	}
	F0R(j,8) if (c2[j].s > c1[j].s) t2 = min(t2,7-c2[j].s);
	F0R(j,8) if (c1[j].f < c2[j].f) t1 = min(t1,c1[j].f);
	
	if (t1 <= t2) cout << 'A';
	else cout << 'B';
}