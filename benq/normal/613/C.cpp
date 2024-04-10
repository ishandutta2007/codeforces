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

int n; 
vi nums;
int sum = 0, mx = 0;

void construct(int gcd) {
	int mult = sum/gcd;
	F0R(i,n) nums[i] /= mult;
	vector<char> ans(gcd);
	int c = 0;
	F0R(i,n) F0R(j,nums[i]/2) {
		ans[c] = ans[gcd-1-c] = char('a'+i);
		c++;
	} 
	F0R(i,n) if (nums[i] % 2 == 1) ans[gcd/2] = char('a'+i);
	F0R(i,mult) F0R(j,gcd) cout << ans[j];
}

int posi (int gcd) {
	if (sum % gcd != 0) return 0;
	
	int mult = sum/gcd;
	F0R(i,n) if (nums[i] % mult != 0) return 0;
	
	vi nums1 = nums;
	F0R(i,n) nums1[i] = nums[i]/mult;
	
	int c = 0;
	
	if (gcd % 2 == 0) {
		F0R(i,n) if (nums1[i] % 2 == 1) c++;
		if (c>0) return 0;
		return 2*mult;
	} else {
		F0R(i,n) if (nums1[i] % 2 == 1) c++;
		if (c>1) return 0;
		return mult;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; nums.resize(n);
	F0R(i,n) {
		cin >> nums[i];
		sum += nums[i];
	}
	FOR(i,1,sum+1) mx = max(mx,posi(i));
	cout << mx << "\n";
	if (mx == 0) {
		F0R(i,n) F0R(j,nums[i]) cout << char('a'+i);
	} else if (posi(sum/mx)) construct(sum/mx);
	else construct(2*sum/mx);
}