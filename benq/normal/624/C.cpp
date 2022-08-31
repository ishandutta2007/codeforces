#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int n, m, edges[501], grid[501][501];
int ans[501];

int main() {
	cin >> n >> m;
	if (m == n*(n-1)/2) {
		cout << "Yes" << endl;
		F0R(i,n) cout << 'a';
		return 0;
	}
	F0R(i,m) {
		int a,b;
		cin >> a >> b;
		grid[a][b] = grid[b][a] = 1;
		edges[a]++; 
		edges[b]++;
	}
	
	FOR(i,1,n+1) if (edges[i] == n-1) ans[i] = 2;
	
	int x = 1;
	while (edges[x] == n-1) x++;
	ans[x] = 1;
	FOR(i,1,n+1) if (ans[i] != 2 && grid[i][x]) ans[i] = 1;
	FOR(i,1,n+1) if (ans[i] == 0) ans[i] = 3;
	
	FOR(i,1,n+1) FOR(j,i+1,n+1) {
		if (abs(ans[i]-ans[j]) <= 1 && !grid[i][j]) {
			cout << "No";
			return 0;
		} 
		if (abs(ans[i]-ans[j]) == 2 && grid[i][j]) {
			cout << "No";
			return 0;
		} 
	}
	cout << "Yes" << endl;
	FOR(i,1,n+1) cout << char(ans[i]+'a'-1);
	return 0;
}