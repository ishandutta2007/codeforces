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
// #define b begin
// #define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;

int main() {
	int n, k, x,z, ans=0,s,e;
	vi arr, a,b, temp;
	cin >> n >> k;
	F0R(i,n) {
		cin >> x;
		arr.pb(x);
	}
	temp = arr;
	int cost = 0, end = -1;
	F0R(i,n) {
		while (end<n-1 && (arr[end+1] || cost<k)) {
			end++;
			if (arr[end] == 0) cost++;
		}
		if (end-i+1 > ans) {
			ans = end-i+1;
			s = i;
			e = end;
		}
		if (arr[i] == 0) cost--; 
	}
	cout << ans << endl;
	FOR(i,s,e+1) arr[i] = 1;
	F0R(i,n) cout << arr[i] << " ";
	return 0;
}