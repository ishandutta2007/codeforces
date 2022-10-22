#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int LOG = 20;

int n, a[MAXN], b[MAXN];
int ss[LOG][MAXN], tt[LOG][MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]), ss[0][i] = a[i];
	for (int i = 0; i < n; i++)	scanf("%d", &b[i]), tt[0][i] = b[i];

	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < n; i++)
			if (i + (1<<w-1) >= n)
				ss[w][i] = ss[w - 1][i], tt[w][i] - tt[w - 1][i];
			else
				ss[w][i] = max(ss[w - 1][i], ss[w - 1][i + (1<<w-1)])
					, tt[w][i] = min(tt[w - 1][i], tt[w - 1][i + (1<<w-1)]);

	ll ans = 0;
	for (int i = 0; i < n; i++){
		int l = i, r = i;
		int mn = 1e9, mx = -1e9;
		int mn2 = 1e9, mx2 = -1e9;
		for (int w = LOG - 1; ~w; w--){
			if (l+(1<<w) <= n && min(mn, tt[w][l]) > max(mx, ss[w][l]))
				mn = min(mn, tt[w][l]), mx = max(mx, ss[w][l]), l += 1<<w;
			if (r+(1<<w) <= n && min(mn2, tt[w][r]) >= max(mx2, ss[w][r]))
				mn2 = min(mn2, tt[w][r]), mx2 = max(mx2, ss[w][r]), r += 1<<w;
		}
		ans += r - l;
	}
	printf("%I64d\n", ans);
	return 0;
}