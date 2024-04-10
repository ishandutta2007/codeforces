#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int MOD = 1000000007;

pii num[100001];
int po2[100001];

int fac(int x) {
	vi pr;
	FOR(i,2,x+1) {
		if (i*i > x) {
			pr.pb(x);
			break;
		}
		if (x % i == 0) {
			x /= i;
			pr.pb(i);
		}
		while (x % i == 0) x /= i;
	}
	F0R(i,1<<pr.size()) {
		pii c = {1,0};
		F0R(j,pr.size()) if (i & (1<<j)) c.f *= pr[j], c.s++;
		num[c.f].f = c.s;
		num[c.f].s ++;
	}
}

int main() {
	po2[0] = 1;
	FOR(i,1,100001) po2[i] = (2*po2[i-1]) % MOD;
	int n; cin >> n;
	F0R(i,n) {
		int a; cin >> a;
		fac(a);
	}
	// start with all, subtract with gcd 2, subtract with gcd 3, add with gcd 2,3
	int ans = 0;
	FOR(i,1,100001) if (num[i].s) {
		if (num[i].f % 2 == 1) ans = (ans+MOD-po2[num[i].s]+1) % MOD;
		else ans = (ans+po2[num[i].s]-1) % MOD;
	}
	cout << ans;
}