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
	int a,b,n; cin >> a >> b >> n;
	double mina = 1000;
	F0R(i,n) {
		int x,y,v; cin >> x >> y >> v;
		mina = min(mina,sqrt(double(x-a)*(x-a)+(y-b)*(y-b))/v);
	}
	cout << fixed << setprecision(10) << mina;
	return 0;
}