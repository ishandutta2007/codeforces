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

int find (pii a, pii b) {
	if (a.f == b.f) {
		if (a.s < b.s) {
			return 1;
		} else return 3;
	} else {
		if (a.f<b.f) {
			return 4;
		} else return 2;
	}
}

int main() {
	int n, ans=0;
	pii track[1005];
	cin >> n;
	F0R(i,n+1) {
		cin >> track[i].f >> track[i].s;
	}
	track[n+1]=track[1];
	F0R(i,n) {
		int x = find (track[i],track[i+1]);
		int y = find (track[i+1],track[i+2]);
		if (y-x == 1 || y-x == -3) ans++;
	}
	cout << ans;
	return 0;
}