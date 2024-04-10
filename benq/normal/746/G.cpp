#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

vi nodes[200000];
vi par[200000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,t,k; cin >> n >> t >> k;
	int cur = 1, curk = n-t;
	nodes[0].pb(cur++);
	FOR(i,1,t+1) {
		int x; cin >> x;
		F0R(j,x) {
			nodes[i].pb(cur++);
			par[i].pb(nodes[i-1][0]);
		}
	}
	if (curk<k) {
		cout << -1;
		return 0;
	}
	
	FOR(i,1,t+1) {
		bool flag = 0;
		FOR(j,1,min(nodes[i].size(),nodes[i-1].size())) {
			if (curk == k) {
				flag = 1;
				break;
			}
			par[i][j] = nodes[i-1][j];
			curk --;
		}
		if (flag == 1) break;
	}
	if (curk != k) {
		cout << -1;
		return 0;
	}
		cout << n << "\n";
	FOR(i,1,t+1) {
		F0R(j,nodes[i].size()) 
			cout << nodes[i][j] << " " << par[i][j] << "\n";
	}
}