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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m, minx = MOD, maxx = -1, miny = MOD, maxy = -1, co = 0;
	cin >> n >> m;
	F0R(i,n) F0R(j,m) {
		char x; cin >> x;
		if (x == 'X') {
			maxx = max(maxx,j);
			minx = min(minx,j);
			maxy = max(maxy,i);
			miny = min(miny,i);
			co ++;
		}
	}
	if (co == (maxx-minx+1)*(maxy-miny+1)) cout << "YES";
	else cout << "NO";
	return 0;
}