#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	ll grid[500][500];
	pii x;
	F0R(i,n) F0R(j,n) {
		cin >> grid[j][i];
		if(grid[j][i] == 0) x = mp(j,i);
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	ll sum1 = 0, sum2 = 0, sol;
	if (x.f == 0) F0R(i,n) sum1 += grid[1][i];
	else F0R(i,n) sum1 += grid[0][i];
	F0R(i,n) sum2 += grid[x.f][i];
	sol = grid[x.f][x.s] = sum1-sum2;
	if (sol <= 0) {
		cout << -1;
		return 0;
	}
	F0R(i,n) {
		ll sum = 0;
		F0R(j,n) sum += grid[i][j];
		if (sum != sum1) {
			cout << -1;
			return 0;
		}
	}
	F0R(j,n) {
		ll sum = 0;
		F0R(i,n) sum += grid[i][j];
		if (sum != sum1) {
			cout << -1;
			return 0;
		}
	}
	ll sum = 0;
	F0R(i,n) sum += grid[i][i];
	if (sum != sum1) {
		cout << -1;
		return 0;
	}
	sum = 0;
	F0R(i,n) sum += grid[i][n-1-i];
	if (sum != sum1) {
		cout << -1;
		return 0;
	}
	cout << sol;
}