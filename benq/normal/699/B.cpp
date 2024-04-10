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
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int n,m; 
vector<pii> nums;
pii a,b=mp(-1,-1);

bool test (int x, int y) {
	for (pii k: nums) if (k.f != x && k.s != y) {
		return false;
	}	
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,n) F0R(j,m) {
		char x; cin >> x;
		if (x == '*') nums.pb(mp(i,j));
	}
	if (nums.size() == 0) {
		cout << "YES" << endl << 1 << " " << 1;
		return 0;
	}
	pii a = nums[0];
	FOR(i,1,nums.size()) if (nums[i].f != a.f && nums[i].s != a.s) {
		b = nums[i];
		break;
	}
	if (b == mp(-1,-1)) {
		cout << "YES" << endl << (a.f+1) << " " << (a.s+1);
		return 0;
	}
	if (test(a.f,b.s)) {
		cout << "YES" << endl << (a.f+1) << " " << (b.s+1);
		return 0;
	}
	if (test(b.f,a.s)) {
		cout << "YES" << endl << (b.f+1) << " " << (a.s+1);
		return 0;
	}
	cout << "NO";
	return 0;
}