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

int n,k; 
	vector<pair<char,int>> need;

void input() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) {
		int z; cin >> z;
		if (z<0) {
			if (need.size() && need[need.size()-1].f == 'W') need[need.size()-1].s++;
			else need.pb(mp('W',1));
			k --;
		} else {
			if (need.size() && need[need.size()-1].f == 'S') need[need.size()-1].s++;
			else need.pb(mp('S',1));
		}
	}
}

int main() {
	input();
	if (k<0) {
		cout << -1;
		return 0;
	}
	if (need.size() == 1 && need[0].f == 'S') {
		cout << 0;
		return 0;
	}
	if (need[0].f == 'S') need.erase(need.begin());
	
	// for (auto a: need) cout << a.f << " " << a.s << "\n";
	// cout << "K " << k << "\n";
	vi n1;
	if (need[need.size()-1].f == 'S') {
		int ans = need.size();
		int ans1 = ans, k1 = k;
		for (auto a: need) if (a.f == 'S') n1.pb(a.s);
		n1.erase(n1.begin()+n1.size()-1);
		sort(n1.begin(),n1.end());
		F0R(j,n1.size()) if ((k-n1[j]) >= 0) k -= n1[j], ans -= 2; 
		
		k1 -= need[need.size()-1].s; ans1--;
		// cout << k1 << " " << ans1 << "\n";
		F0R(j,n1.size()) if ((k1-n1[j]) >= 0) k1 -= n1[j], ans1 -= 2; 
		
		if (k1>=0) cout << min(ans1,ans);
		else cout << ans;
	} else {
		for (auto a: need) if (a.f == 'S') n1.pb(a.s);
		sort(n1.begin(),n1.end());
		int ans = need.size();
		F0R(j,n1.size()) if (k-n1[j] >= 0) k -= n1[j], ans -= 2; 
		cout << ans;
	}
}