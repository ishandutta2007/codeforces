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
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int c[500],n,k;
bool arr[501][501][501], done[501][501];

void dp(int csum, int ccoin) {
	if ((ccoin == n && csum != k) || csum > k) return;
	if (csum == k) {
		arr[k][ccoin][0] = true; 
		return;
	}
	if (done[csum][ccoin]) return;
	
	done[csum][ccoin] = 1; 
	dp(csum,ccoin+1);
	if (arr[csum][ccoin+1][0]) F0R(i,k+1) arr[csum][ccoin][i] = arr[csum][ccoin+1][i];
	
	dp(csum+c[ccoin],ccoin+1);
	if ((csum+c[ccoin]) <= k && arr[csum+c[ccoin]][ccoin+1][0]) {
		F0R(i,k+1-c[ccoin]) {
			arr[csum][ccoin][i+c[ccoin]] = arr[csum][ccoin][i+c[ccoin]] || arr[csum+c[ccoin]][ccoin+1][i];
		}
		F0R(i,k+1) arr[csum][ccoin][i] = arr[csum][ccoin][i] || arr[csum+c[ccoin]][ccoin+1][i];
	} 
	/*cout << csum << " " << ccoin << endl;
	F0R(i,k+1) cout << arr[csum][ccoin][i] << " ";
	cout << endl;*/
}

int main() {
	ios_base::sync_with_stdio(0); cin >> n >> k;
	F0R(i,n) cin >> c[i];
	dp(0,0);
	int ans = 0;
	F0R(i,k+1) if (arr[0][0][i]) ans ++;
	cout << ans << endl;
	F0R(i,k+1) if (arr[0][0][i]) cout << i << " ";
	// cout << endl;
	// F0R(i,6) cout << arr[18][i][0] << " ";
}