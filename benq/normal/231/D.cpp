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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int x,y,z,x1,y1,z1; cin >> x >> y >> z >> x1 >> y1 >> z1;
	int a1, a2, a3, a4, a5, a6; cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	int ans = 0;
	if (y<0) ans += a1;
	if (y>y1) ans += a2;
	if (x<0) ans += a5;
	if (x>x1) ans += a6;
	if (z<0) ans += a3;
	if (z>z1) ans += a4;
	cout << ans;
}