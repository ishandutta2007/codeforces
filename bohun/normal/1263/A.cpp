#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

int T;
int t[3];
 
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", t, t + 1, t + 2);
		sort(t, t + 3);
		int ans = min(t[0] + t[1], t[2]);
		int l = 0;
		int r = 1e8;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if(t[0] + t[1] - 2 * m >= ans)
				l = m;
			else
				r = m - 1;
		}
		printf("%d\n", ans + l);
	}
		

	
	
	
	
	return 0;
}