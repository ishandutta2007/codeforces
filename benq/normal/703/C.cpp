#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,w,v,u; cin >> n >> w >> v >> u;
	cout << fixed << setprecision(10);
	double a1 = 0;
	vector<pair<ll,ll>> po(n);
	F0R(i,n) cin >> po[i].f >> po[i].s;
	a1 = double(w)/u;
	F0R(i,n) a1 = max(a1,double(w-po[i].s)/u+double(po[i].f)/v);
	bool z = 1;
	F0R(i,n) {
		if ((po[i].f*u)<(po[i].s*v)) {
			z = 0;
			break;
		}
	}
	if (z) cout << double(w)/u;
	else cout << a1;
}