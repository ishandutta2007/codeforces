#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int arr[100][100],n,k;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	if (k>n*n) {
		cout << -1;
		return 0;
	}
	F0R(i,n) FOR(j,i,n) {
		if (k == 0) break;
		if (j == i) {
			k --;
			arr[i][j] = 1;
		} else if (k >= 2) {
			k -= 2;
			arr[i][j] = arr[j][i] = 1;
		}
	}
	F0R(i,n) {
		F0R(j,n) cout << arr[i][j] << " ";
		cout << "\n";
	}
}