#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int arr[49][49];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	int ev = n*n/2, od = n*n/2+1;
	F0R(i,n) arr[i][n/2] = 1, arr[n/2][i] = 1;
	od -= (2*n-1);
	od /= 4;
	F0R(i,n/2) F0R(j,i) {
		if (od > 1) {
			arr[i][j] = 1;
			arr[i][n-1-j] = 1;
			arr[n-1-i][j] = 1;
			arr[n-1-i][n-1-j] = 1;
			arr[j][i] = 1;
			arr[j][n-1-i] = 1;
			arr[n-1-j][n-1-i] = 1;
			arr[n-1-j][i] = 1;
			od -= 2;
		}
		if (od == 1) {
			arr[0][0] = 1;
			arr[0][n-1] = 1;
			arr[n-1][0] = 1;
			arr[n-1][n-1] = 1;
		}
	}
	int co = 1, ce = 2;
	F0R(i,n) {
		F0R(j,n) {
			// cout << arr[i][j];
			if (arr[i][j]) {
				cout << co << " ";
				co += 2;
			} else {
				cout << ce << " ";
				ce += 2;
			}
		}
		cout << "\n";
	}
	return 0;
}