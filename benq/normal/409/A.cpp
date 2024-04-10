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
	string a,b; cin >> a >> b;
	int x1 = 0, x2 = 0;
	F0R(i,a.length()/2) {
		string s1 = a.substr(2*i,2), s2 = b.substr(2*i,2);
		if (s1 == "[]") {
			if (s2 == "8<") x2 ++;
			else if (s2 == "()") x1++;
		} else if (s1 == "8<") {
			if (s2 == "[]") x1++;
			else if (s2 == "()") x2++;
		} else {
			if (s2 == "8<") x1++;
			else if (s2 == "[]") x2++;
		}
	}
	// cout << x1 << " " << x2 << "\n";
	if (x1>x2) cout << "TEAM 1 WINS";
	else if (x1<x2) cout << "TEAM 2 WINS";
	else cout << "TIE";
	return 0;
}