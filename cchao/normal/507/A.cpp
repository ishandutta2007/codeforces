#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef complex<double> cd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ria(a, n) rep(_, n) ri(a[_])
#define pia(a, n) rep(_, n) printf("%d ", a[_])
#define pi(x) printf("%d\n", x)
#define PB push_back
#define SZ size()
#define fst first
#define snd second
#define Ttimes int T; scanf("%d", &T); while(T--)
#define CASE  int T; scanf("%d", &T); for(int ks = 1; ks <= T; ++ks)

int main() {
	int n; ri(n);
	int k; ri(k);
	vector<int> a(n), b(n);
	ria(a, n);
	rep(i, n) b[i] = i;
	sort(b.begin(), b.end(), [&](int x, int y){return a[x] < a[y]; });

	int cur = 0;
	vector<int> aa;
	rep(i, n) if(cur + a[b[i]] <= k) {
		aa.push_back(b[i] + 1);
		cur += a[b[i]];
	}
	sort(aa.begin(), aa.end());
	pi((int)aa.size());
	if(aa.size()) { pia(aa, aa.size()); puts(""); }
	

	return 0;
}