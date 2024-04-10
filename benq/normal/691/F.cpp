#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;

#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

unordered_map<int,ll> a;
vector<ll> nums;
ll ans[3000000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n; cin >> n;
	F0R(i,n) {
		int x; cin >> x;
		a[x]++;
		nums.pb(x);
	}
	sort(nums.begin(),nums.end());
	nums.erase(unique(nums.begin(),nums.end()),nums.end());
	F0R(i,nums.size()) {
		if (nums[i]*nums[i] < 3000000) {
			ans[nums[i]*nums[i]] += a[nums[i]]*(a[nums[i]]-1)/2;
			FOR(j,i+1,nums.size()) {
				if (nums[i]*nums[j] < 3000000)
					ans[nums[i]*nums[j]] += a[nums[i]]*a[nums[j]];
				else break;
			}
		} else break;
	}
	FOR(i,1,3000000) ans[i] += ans[i-1];
	int m; cin >> m;
	F0R(i,m) {
		int k; cin >> k;
		cout << n*(n-1)-2*ans[k-1] << "\n";
	}
}