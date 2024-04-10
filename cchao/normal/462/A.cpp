#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
char s[110][110];
int main() {
	int n; ri(n);
	rep(i, n) scanf("%s", s[i]);
	rep(i, n) rep(j, n) {
		int cnt = 0;
		rep(k, 4) {
			int ti = i + dx[k];
			int tj = j + dy[k];
			if(ti < n && tj < n && ti >= 0 && tj >=0 && s[ti][tj] == 'o') cnt++;
		}
		if(cnt&1) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}