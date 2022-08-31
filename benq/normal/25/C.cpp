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

ll d[300][300];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	F0R(i,n) F0R(j,n) cin >> d[i][j];
	int k; cin >> k;
	F0R(i,k) {
		ll a,b,c; cin >> a >> b >> c;
		a--, b--;
		d[a][b] = min(d[a][b],c);
		d[b][a] = min(d[b][a],c);
		ll ans = 0;
		F0R(j,n) F0R(k,n) {
			d[j][k] = min(d[j][k],min(d[j][a]+d[b][k]+d[a][b],d[j][b]+d[a][k]+d[a][b]));
			ans += d[j][k];
		}
		cout << ans/2 << " ";
	}
}