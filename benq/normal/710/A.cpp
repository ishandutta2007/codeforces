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
	char x; int y; cin >> x >> y;
	int x1 = int(x-'a'); y--;
	if (x1 == 0 || x1 == 7) {
		if (y == 0 || y == 7) cout << 3;
		else cout << 5;
	} else {
		if (y == 0 || y == 7) cout << 5;
		else cout << 8;
	}
	return 0;
}