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

void getFail(int *P, int *f, int m) {
	f[0] = f[1] = 0;
	for(int i = 1; i < m; ++i) {
		int j = f[i];
		while(j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i] == P[j] ? j + 1 : 0;
	}
}

int ffind(int *T, int *P, int *f, int n, int m) {
	int ans = 0;
	for(int i = 0, j = 0; i < n; ++i) {
		while(j && P[j] != T[i]) j = f[j];
		if(P[j] == T[i]) ++j;
		if(j == m) {
			ans++;
			j = f[j];
		}
	}
	return ans;
}

#define Ttimes int T; scanf("%d", &T); while(T--)
const int maxn = 200000 + 20;
int n, w, a[maxn], b[maxn], aa[maxn],bb[maxn], f[maxn];
int main() {
	rii(n, w); ria(aa, n); ria(bb, w);
	if(w == 1) {
		pi(n);
		return 0;
	}
	rep(i,n-1) a[i]=aa[i+1]-aa[i]; n--;
	rep(i,w-1) b[i]=bb[i+1]-bb[i]; w--;
	getFail(b, f, w);
	cout << ffind(a, b, f, n, w) << endl;

	return 0;
}