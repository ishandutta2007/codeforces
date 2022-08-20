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

set<ll> posi;
vi arr;
ll sum = 0, cur = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n; arr.resize(n);
	F0R(i,n) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum % 2 != 0) {
		cout << "NO";
		return 0;
	}
	posi.insert(0);
	F0R(i,n) {
		if (posi.find(sum/2-arr[i]) != posi.end()) {
			cout << "YES";
			return 0;
		}
		cur += arr[i];
		posi.insert(cur);
	}
	posi.clear(); reverse(arr.begin(),arr.end());
	posi.insert(0), cur = 0;
	F0R(i,n) {
		if (posi.find(sum/2-arr[i]) != posi.end()) {
			cout << "YES";
			return 0;
		}
		cur += arr[i];
		posi.insert(cur);
	}
	cout << "NO";
}