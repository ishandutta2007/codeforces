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
	int n; cin >> n;
	int cur = 0;
	F0R(i,n) {
		int x;
		string dir;
		cin >> x >> dir;
		if (cur == 0 && dir != "South") {
			cout << "NO";
			return 0;
		}
		if (cur == 20000 && dir != "North") {
			cout << "NO";
			return 0;
		}
		if (dir == "South") cur += x;
		else if (dir == "North") cur -= x;
		if (cur<0 || cur>20000) {
			cout << "NO";
			return 0;
		}
	}
	if (cur == 0) cout << "YES";
	else cout << "NO";
	return 0;
}