#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int LOG = 37;

int n;
ll k;
ll mn[LOG][MAXN], sm[LOG][MAXN];
int nxt[LOG][MAXN];

int main(){
	scanf("%d %lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &nxt[0][i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &mn[0][i]), sm[0][i] = mn[0][i];

	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < n; i++)
			nxt[w][i] = nxt[w - 1][nxt[w - 1][i]]
				, mn[w][i] = min(mn[w - 1][i], mn[w - 1][nxt[w - 1][i]])
				, sm[w][i] = sm[w - 1][i] + sm[w - 1][nxt[w - 1][i]];

	for (int i = 0; i < n; i++){
		ll x = 1e18, y = 0, rem = k, cur = i;
		for (int w = LOG - 1; ~w; w--)
			if (rem >= (1ll<<w))
				rem -= 1ll<<w, x = min(x, mn[w][cur]), y += sm[w][cur], cur = nxt[w][cur];
		printf("%lld %lld\n", y, x);
	}
	return 0;
}