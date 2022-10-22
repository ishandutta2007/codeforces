#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

int n;
int T;
map <ll, int> last;
ll x, y; 
 
int main() {	
	scanf("%d", &T);
	FOR(i, T) {
		last.clear();
		scanf("%lld %lld", &x, &y);
		bool bad = 0;
		while(x < y && last.find(x) == last.end()) {
			last[x] = 1;
			if(x % 2 == 0) {
				x = (ll) 3 * x / 2;
				continue;
			}
			if(x == 1) {
				bad = 1;
				break;
			}
			x -= 1;
			x = (ll) 3 * x / 2;
		}
		if(bad == 1 || x < y) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	
	
	return 0;
}