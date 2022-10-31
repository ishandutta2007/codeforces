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

int n, a[2010], c[2010]={}, f[2010]={1};
vector<int> v[2010]; int sz = 0;
void dfs(int x) {
	if(x == sz+1) {
		n--;
		for(int i = 0; i <= sz; ++i) {
			rep(j, v[i].size()) printf("%d ", v[i][j]);
		}
		puts("");
		return ;
	}
	do {
		if(n == 0) break;
		dfs(x+1);
	}while(next_permutation(v[x].begin(), v[x].end()));
}
int b[2010];
int main() {
	ri(n); ria(a, n);
	rep(i, n) c[a[i]]++;
	rep(i,2010) if(i) f[i] = min(f[i-1]*i,2000);
	long long m = 1;
	rep(i,2010) {
		m *= f[c[i]];
		if(m >= 3) break;
	}
	if(m < 3) { puts("NO"); return 0; }
	rep(i,n) b[i]=a[i];
	sort(b,b+n);
	int nn = unique(b,b+n)-b;
	sz = nn - 1;
	for(int i = 0; i < n; ++i) {
		v[lower_bound(b,b+nn,a[i])-b].push_back(i+1);
	}
	puts("YES");
	n = 3; dfs(0);
	return 0;
}