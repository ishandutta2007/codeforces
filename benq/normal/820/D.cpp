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

int n, numgreat, cshift = 0, bshift = -1;
ll cans = 0, bans = 1e18;
vi p;
int cur[3000001];

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; p.resize(n);
	F0R(i,n) {
		cin >> p[i]; p[i] --;
		cur[p[i]-i+1000000] ++;
		if (p[i] > i) numgreat ++;
		cans += abs(p[i]-i);
	}
}

int main() {
	init();
	// p[i]-i
	F0R(i,n) {
		// cout << i << " " << cans << " " << numgreat << "\n";
		if (cans < bans) {
			bans = cans;
			bshift = cshift;
		}
		cans -= numgreat;
		cans += (n-numgreat);
		cshift ++; // subtract 1 from everything
		numgreat -= cur[cshift+1000000];
		
		//cout << "HI " << cans << "\n";
		// move last element to beginning
		cur[cshift+1000000+p[n-1-i]-n] --;
		cur[cshift+1000000+p[n-1-i]] ++;
		if (p[n-1-i] != 0) numgreat ++;
		cans -= abs(p[n-1-i]-n);
		cans += abs(p[n-1-i]);
	}
	
	cout << bans << " " << bshift;
}