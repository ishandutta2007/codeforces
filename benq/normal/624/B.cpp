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

int main() {
	int n;
	cin >> n;
	vector<ll> nums;
	F0R(i,n) {
		int a;
		cin >> a;
		nums.pb(a);
	}
	sort(nums.begin(), nums.end());
	ll ans = 0, curmax = 1999999999;
	for (int i = nums.size()-1; i >= 0; --i) {
		curmax = min(nums[i],curmax-1);
		if (curmax <= 0) break;
		ans += curmax;
	}
	cout << ans;
	return 0;
}