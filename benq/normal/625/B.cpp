#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
// #define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

string a,b;
vi x;

int main() {
	cin >> a >> b;
	// F0R(i,100000) a += 'a';
	// b = "a";
	if (a.length()<b.length()) {
		cout << 0;
		return 0;
	}
	F0R(i,a.length()-b.length()+1) if (a.substr(i,b.length()) == b) x.pb(i);

	// cout << x.size() << " " << x[0] << endl;
	if (x.size() == 0) {
		cout << 0;
		return 0;
	} else {
		int ans = 0,curind = 0, cur=0;
		while (curind<x.size()) {
			cur = x[curind]+b.length();
			while (cur>x[curind] && curind<x.size()) curind++;
			ans ++;
		}
		cout << ans;
	}
	return 0;
}