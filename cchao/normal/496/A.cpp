#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

int a[110], n;
int main() {
	ri(n); ria(a, n);
	int ans = 1000000, ans2 = 0;
	rep(i, n) {
		if(i) ans2 = max(ans2, a[i+1] - a[i]);
		if(i == 0 || i == n - 1) continue;
		ans = min(ans, a[i+1] - a[i-1]);
	}
	pi(max(ans, ans2));
	return 0;
}