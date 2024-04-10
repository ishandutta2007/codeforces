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
 
int grid[401][401];
 
int main() {
	int n,curx = 200, cury=200,ans=0;
	cin >> n;
	grid[200][200]++;
	F0R(i,n) {
		char a;
		cin >> a;
		if (a == 'U') cury++;
		else if (a == 'D') cury --;
		else if (a == 'R') curx++;
		else curx--;
		grid[curx][cury] ++;
	}
	F0R(i,401) F0R(j,401) {
		ans += (grid[i][j]*(grid[i][j]-1))/2;
	}
	cout << ans;
	return 0;
}