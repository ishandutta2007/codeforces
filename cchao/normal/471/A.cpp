#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair

#define rep(i, n) for(int i = 0; i < n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)


int main() {
	int a[6], c[10]={};
	rep(i, 6) {
		ri(a[i]); c[a[i]]++;
	}
	int b = -1;
	rep(i, 10) if(c[i] >= 4) b = i;
	if(b == -1) puts("Alien");
	else {
		int t = 4;
		rep(i, 6) if(a[i] == b) {
			a[i] = 10;
			t--;
			if(t == 0) break;
		}
		sort(a, a + 6);
		puts(a[0] < a[1] ? "Bear" : "Elephant");
	}
	return 0;
}