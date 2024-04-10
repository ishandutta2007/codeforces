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

set<int> e, o;
vi input;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m; cin >> n >> m;
	F0R(i,n) {
		int num; cin >> num;
		if (num % 2 == 0) e.insert(num);
		else o.insert(num);
		input.pb(num);
	}
	while (e.size()>n/2) e.erase(e.begin());
	while (o.size()>n/2) o.erase(o.begin());
	FOR(i,1,m+1) {
		if (e.size() == n/2) break;
		if (i % 2 == 0 && e.find(i) == e.end()) e.insert(i);
	}
	// for (int i: e) cout << i << " hi ";
	FOR(i,1,m+1) {
		if (o.size() == n/2) break;
		if (i % 2 == 1 && o.find(i) == o.end()) o.insert(i);
	}
	if (e.size() != n/2 || o.size() != n/2) {
		cout << -1;
		return 0;
	}
	int ans = 0;
	F0R(i,input.size()) {
		if (o.find(input[i]) != o.end()) o.erase(input[i]);
		else if (e.find(input[i]) != e.end()) e.erase(input[i]);
		else input[i] = -1, ans++;
	}
	cout << ans << "\n";
	F0R(i,input.size()) {
		if (input[i] == -1) {
			if (e.size()>0) {
				input[i] = *e.begin();
				e.erase(e.begin());
			} else {
				input[i] = *o.begin();
				o.erase(o.begin());
			}
		}
		cout << input[i] << " ";
	}
}