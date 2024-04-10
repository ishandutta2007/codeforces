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
#define b begin()
#define e end()
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int n, nums[1000], used[1000], ans = -1, ans1 = -1,cur;
bool x = 0;

int main() {
	cin >> n;
	F0R(i,n) cin >> nums[i];
	while (cur < n) {
		if (x == 0) {
			F0R(i,n) if (!used[i] && cur >= nums[i]) {
				used[i] = 1, cur++;
			}
			x = 1;
		} else {
			for (int i = n-1; i >= 0; --i) if (!used[i] && cur >= nums[i]) {
				used[i] = 1, cur++;
			}
			x = 0;
		}
		ans ++;
	}
	cout << ans;
	return 0;
}