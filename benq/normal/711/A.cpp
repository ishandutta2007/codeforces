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
	vector<string> ans;
	bool f = 0;
	F0R(i,n) {
		string s; cin >> s;
		if (f == 0 && s.substr(0,2) == "OO") {
			s[0] = '+', s[1] = '+';
			f = 1;
		}
		if (f == 0 && s.substr(3,2) == "OO") {
			s[3] = '+', s[4] = '+';
			f = 1;
		}
		ans.pb(s);
	}
	if(f == 0) cout << "NO";
	else {
		cout << "YES\n";
		for (string s: ans) cout << s << "\n";
	}
	return 0;
}