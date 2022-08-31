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

vi gen, type;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	while (cin >> s) {
		reverse(s.begin(),s.end());
		if (s.length()>=4 && s.substr(0,4) == "soil") gen.pb(0), type.pb(0);
		else if (s.length()>=5 && s.substr(0,5) == "alail") gen.pb(1), type.pb(0);
		else if (s.length()>=3 && s.substr(0,3) == "rte") gen.pb(0), type.pb(1);
		else if (s.length()>=4 && s.substr(0,4) == "arte") gen.pb(1), type.pb(1);
		else if (s.length()>=6 && s.substr(0,6) == "sitini") gen.pb(0), type.pb(2);
		else if (s.length()>=6 && s.substr(0,6) == "setini") gen.pb(1), type.pb(2);
		else {
			cout << "NO";
			return 0;
		}
	}
	if (gen.size() == 1) {
		cout << "YES";
		return 0;
	}
	F0R(i,gen.size()-1) if (gen[i] != gen[i+1]) {
		cout << "NO";
		return 0;
	}
	F0R(i,type.size()-1) if (type[i+1]-type[i]>1 || type[i+1]-type[i]<0) {
		cout << "NO";
		return 0;
	}
	int ccount = 0;
	F0R(i,type.size()) if (type[i] == 1) ccount++;
	if (ccount != 1) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
}