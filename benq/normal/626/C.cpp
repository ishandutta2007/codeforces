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
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	int n,m, cur6=0, cur2, cur3;
	cin >> n >> m;
	if (n % 2 == 1) cur2 = 3*n-1;
	else cur2 = 3*n-2;
	cur3 = 6*m-3;
	while ((cur6+6)<max(cur2,cur3)) {
		if (cur2 > cur3) {
			if (cur2 % 6 == 4) cur2 -= 2;
			else cur2 -= 4;
			cur6 += 6;
		} else {
			cur3 -= 6;
			cur6 += 6;
		}
	}
	cout << max(max(cur2,cur3),cur6);
	// cout << cur2 << " " << cur3 << " " << cur6;
	return 0;
}