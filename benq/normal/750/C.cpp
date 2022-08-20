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
	int n, cur = 0; cin >> n;
	vi d2, d1;
	F0R(i,n) {
		int c,d; cin >> c >> d;
		if (d == 1) d1.pb(cur);
		else d2.pb(cur);
		cur += c;
	}
	sort(d2.begin(),d2.end());
	// for (int i: d2) cout << i << "\n";
	sort(d1.begin(),d1.end());
	if (d2.size() == 0) cout << "Infinity";
	else if (d1.size() && d2[d2.size()-1] >= d1[0]) cout << "Impossible";
	else {
		cout << 1899-d2[d2.size()-1]+cur;
	}
}