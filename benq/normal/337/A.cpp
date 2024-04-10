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
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	int n,m, ans = 9999;
	vi k;
	cin >> n >> m;
	F0R(i,m) {
		int z;
		cin >> z;
		k.pb(z);
	}
	sort(k.b(),k.e());
	F0R(i,m-n+1) {
		if (k[i+n-1]-k[i]<ans) ans = k[i+n-1]-k[i];
	}
	cout << ans;
	return 0;
}