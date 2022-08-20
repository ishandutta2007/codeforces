#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	int n,d,h, last;
	cin >> n >> d >> h;
	last = h+1;
	if (d>2*h) {
		cout << -1;
		return 0;
	} else if (h == d) {
		if (h == 1) {
			if (n == 2) {
				cout << 1 << " " << 2;
			} else {
				cout << -1;
			}
			return 0;
		}
		F0R(i,h) cout << (i+1) << " " << (i+2) << endl;
		while (last < n) {
			last++;
			cout << (h) << " " << last << endl;
		}
		return 0;
	} else if (d<h) {
		cout << -1;
		return 0;
	}
	
	F0R(i,h) cout << (i+1) << " " << (i+2) << endl;
	for(int i = 0;;i++) {
		F0R(j,d-h) {
			if (last<n) {
				last++;
				if (j == 0) cout << 1 << " " << last << endl;
				else cout << (last-1) << " " << last << endl;
			} else return 0;
		}
	}
	return 0;
}