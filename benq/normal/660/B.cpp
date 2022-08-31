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

int bus[100][4], n,m;

void assign() {
	int c = 1;
	F0R(i,n) {
		bus[i][0] = c;
		c++;
		bus[i][3] = c;
		c++;
	}
	F0R(i,n) {
		bus[i][1] = c;
		c++;
		bus[i][2] = c;
		c++;
	}
}

int main() {
	cin >> n >> m;
	assign();
	F0R(i,n) {
		if (bus[i][1] <= m) cout << bus[i][1] << " ";
		if (bus[i][0] <= m) cout << bus[i][0] << " ";
		if (bus[i][2] <= m) cout << bus[i][2] << " ";
		if (bus[i][3] <= m) cout << bus[i][3] << " ";
	}
	return 0;
}