#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <long long, long long> pii;
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

ll best[20000001];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	ll x,y; cin >> x >> y;
	vi nums;
	while (n) {
		nums.pb(n);
		n /= 2;
	}
	reverse(nums.begin(),nums.end());
	vector<pii> best(nums.size());
	F0R(i,best.size()) {
		best[i].f = nums[i]*x;
		best[i].s = (nums[i]+1)*x;
		if (i == 0) best[i].s = min(2*x,x+y);
		else {
			if (nums[i] == 2*nums[i-1]) best[i].f = min(best[i].f,best[i-1].f+y);
			else best[i].f = min(best[i].f,best[i-1].f+x+y);
			if (nums[i] == 2*(nums[i-1]+1)) best[i].f = min(best[i].f,best[i-1].s+y);
			else best[i].f = min(best[i].f,best[i-1].s+x+y);
			if ((nums[i]+1) == 2*nums[i-1]) best[i].s = min(best[i].s,best[i-1].f+y);
			else best[i].s = min(best[i].s,best[i-1].f+x+y);
			if ((nums[i]+1) == 2*(nums[i-1]+1)) best[i].s = min(best[i].s,best[i-1].s+y);
			else best[i].s = min(best[i].s,best[i-1].s+x+y);
		}
	}
	cout << best[best.size()-1].f;
}