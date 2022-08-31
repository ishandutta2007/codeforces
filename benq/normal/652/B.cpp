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

int n;
vi a,b;
	
int main() {
	cin >> n;
	F0R(i,n) {
		int k;
		cin >> k;
		a.pb(k);
	}
	sort(a.begin(),a.end());
	F0R(i,(n+1)/2) {
		b.pb(a[0]);
		a.erase(a.begin());
	}
	F0R(i,n) {
		if (i % 2 == 0) {
			cout << b[0];
			b.erase(b.begin());
		} else {
			cout << a[0];
			a.erase(a.begin());
		}
		cout << " ";
	}
	return 0;
}