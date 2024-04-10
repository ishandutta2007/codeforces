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
 
char grid[100][100];
 
int main() {
	int n, ans=0;
	cin >> n;
	F0R(i,n) {
		F0R(j,n) {
			cin >> grid[i][j];
		}
	}
	F0R(i,n) {
		int c = 0;
		F0R(j,n) if (grid[i][j] == 'C') c++;
		ans += c*(c-1)/2;
	}
	F0R(i,n) {
		int c = 0;
		F0R(j,n) if (grid[j][i] == 'C') c++;
		ans += c*(c-1)/2;
	}
	cout << ans;
	return 0;
}