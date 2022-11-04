#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int a, b, n;
char s[300005];
int tc[4];

void solve() {
	scanf("%d%d", &a, &b);
	scanf("%s", s + 1); n = strlen(s + 1);
	memset(tc, 0, sizeof(tc));
	int len = 0, ln3 = 0;
	cont(i, n + 1) {
		if (s[i] == '.') ++len;
		else if (len) {
			if (len < b) ++tc[0];
			else if (len < a) ++tc[1];
			else if (len < 2 * b) ++tc[2];
			else ++tc[3], ln3 = len;
			len = 0;
		}
	}
	if (tc[1]) return void(puts("NO"));
	if (tc[3] > 1) return void(puts("NO"));
	if (a >= 2 * b) {
		if (tc[3] && ln3 <= a + 2 * (b - 1)) return void(puts("YES"));
		return void(puts("NO"));
	}
	if (!tc[3] && tc[2] % 2) return void(puts("YES"));
	if (tc[3]) {
		if (tc[2] % 2) {
			if (ln3 >= 2 * a && ln3 <= a + 3 * b - 2) return void(puts("YES"));
		}
		else {
			if (ln3 <= a + 2 * (b - 1)) return void(puts("YES"));
			if (ln3 >= 3 * a && ln3 <= a + 2 * (2 * b - 1)) return void(puts("YES"));
		}
	}
	puts("NO");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}