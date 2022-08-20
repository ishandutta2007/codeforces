#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

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

const int MOD = 1000000007;
double PI = 4*atan(1);

bitset<300000001> comp;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int l,r,ans=0; cin >> l >> r;
	comp[1] = 1;
	for (int i = 3; i < 20000; i += 2) if (!comp[i]) for (int j = 3; i*j <= 300000000; j += 2) comp[i*j] = 1;
	FOR(i,l,r+1) {
		if (i == 2) ans ++;
		else if (i % 4 == 1 && !comp[i]) ans++;
	}
	cout << ans;
}