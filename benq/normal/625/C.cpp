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
	int n,k, grid[500][500];
	int count = 0, sum=0;
	cin >> n >> k;
	F0R(i,n) {
		F0R(j,k-1) {
			count++;
			grid[j][i] = count;
		}
	}
	count++;
	F0R(i,n) {
		grid[k-1][i] = count;
		count += (n-k+1);
		sum += grid[k-1][i];
	}
	F0R(i,n) {
		count = grid[k-1][i];
		FOR(j,k,n) {
			count++;
			grid[j][i] = count;
		}
	}
	cout << sum << endl;
	F0R(i,n) {
		F0R(j,n) {
			cout << grid[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}