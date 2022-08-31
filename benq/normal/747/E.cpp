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

int cur = 1, maxlev = 1, lef[1000000];
vector<string> ans[1000000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	vector<string> lines;
	vi nums;
	
	int y;
	char x;
	while (cin >> x) {
		string s1; s1 += x;
		while (cin >> x) {
			if (x == ',') break;
			else s1 += x;
		}
		lines.pb(s1);
		cin >> y;
		nums.pb(y);
		if (!(cin >> x)) break;
	}
	lef[1] = 1000000;
	// F0R(i,lines.size()) cout << lines[i] << " " << nums[i] << "\n";
	F0R(i,lines.size()) {
		// cout << cur << "\n";
		maxlev = max(maxlev,cur);
		ans[cur].pb(lines[i]);
		if (nums[i]>0) {
			lef[++cur] += nums[i]-1;
		} else if (lef[cur]>0) lef[cur]--;
		else {
			while (lef[cur] == 0) cur--;
			lef[cur]--;
		}
	}
	cout << maxlev << "\n";
	FOR(i,1,maxlev+1) {
		for (string j: ans[i]) cout << j << " ";
		cout << "\n";
	}
}