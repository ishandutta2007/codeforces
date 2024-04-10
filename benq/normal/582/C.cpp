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

unordered_map<int,vi> nums;
bool ok[400001];
int el[200001];
set<int> gcds;
ll ans = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n; 
	FOR(i,1,n+1) cin >> el[i];
	
	FOR(i,1,n) {
		nums[__gcd(i,n)].pb(i);
		gcds.insert(__gcd(i,n));
	}
	
	for (int a: gcds) {
		vi cor(n);
		for (int i: nums[a]) cor[i] ++;
		FOR(i,1,n) cor[i] += cor[i-1];
		memset(ok,0,sizeof ok);
		FOR(i,1,a+1) {
			int mx = 0;
			F0R(j,n/a) mx = max(mx,el[j*a+i]);
			F0R(j,n/a) if (el[j*a+i] == mx) ok[j*a+i] = ok[j*a+i+n] = 1;
		}
		vi best(2*n+1);
		for (int i = 2*n-1; i > 0; --i) {
			if (!ok[i]) best[i] = 0;
			else best[i] = best[i+1]+1;
			if (i <= n) {
				best[i] = min(best[i],n-1);
				ans += cor[best[i]];
			}
		}
	}
	cout << ans;
}