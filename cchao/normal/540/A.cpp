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

int main() {
	char a[1010], b[1010];
	int n; ri(n);
	scanf("%s%s", a, b);
	int ans = 0;
	rep(i, n) {
		int aa = a[i] - b[i];
		int bb = b[i] - a[i];
		if(aa < 0) aa += 10;
		if(bb < 0) bb += 10;
		ans += min(aa, bb);
	}
	printf("%d\n", ans);
	return 0;
}