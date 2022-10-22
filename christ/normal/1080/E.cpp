#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 253; ull BASE = 5e9+6, MOD = 1e15 + 37;
char grid[MN][MN];
bool ok[MN];
int cnt[MN][26], cntOdd[MN], badL[MN], badR[MN];
ull psa[MN][MN]; ll hsh[MN], hsh2[MN], pw[MN];
ui hh (ui x) {
	x += 829859823;
	x = (x^(x>>15))*537825235;
	x = (x^(x>>13))*495739205;
	return x^(x>>16);
}
int main () { 
	int n,m; ll res = 0;
	scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf ("%s",grid[i]+1);
		for (int j = 1; j <= m; j++) psa[i][j] = psa[i][j-1] + hh(grid[i][j] - 'a');
	}
	pw[0] = 1;
	for (int i = 1; i <= n+m; i++) pw[i] = pw[i-1] * BASE;
	double tot = 0;
	for (int l = 1; l <= m; l++) {
		memset(cnt,0,sizeof cnt); memset(cntOdd,0,sizeof cntOdd);
		for (int r = l; r <= m; r++) {
			//printf ("l %d r %d\n",l,r);
			for (int i = 1; i <= n; i++) {
				if ((++cnt[i][grid[i][r]-'a'])&1) ++cntOdd[i];
				else --cntOdd[i];
				ok[i] = cntOdd[i] <= 1;
			}
			int lst = 0;
			for (int i = 1; i <= n; i++) badL[i] = ok[i] ? lst : (lst = i);
			lst = n+1;
			for (int i = n; i >= 1; i--) badR[i] = ok[i] ? lst : (lst = i);
			for (int i = 1; i <= n; i++) hsh[i] = ok[i] ?  hsh[i-1]*BASE+psa[i][r]-psa[i][l-1]: 0;
			for (int i = n; i >= 1; i--) hsh2[i] = ok[i] ? hsh2[i+1]*BASE+psa[i][r]-psa[i][l-1] : 0;
			auto pal = [&] (int hl, int hr) {
				ull ret = (hsh[hr] - hsh[hl-1] * pw[hr-hl+1]);
				ull ret2 = (hsh2[hl] - hsh2[hr+1] * pw[hr-hl+1]);
				return ret == ret2;
			};
			for (int i = 1; i <= n; i++) if (ok[i]) {
				int low = 1, high = min(i-badL[i],badR[i]-i), mid, ans = -1;
				//printf ("low %d high %d pal %d\n",low,high,pal(i,i));
				while (low <= high) {
					mid = (low + high) / 2;
					if (pal(i - mid + 1, i + mid - 1)) low = (ans = mid) + 1;
					else high = mid - 1;
				}
				//printf ("ans %d\n",ans);
				res += ans;
			}
			for (int i = 1; i < n; i++) if (ok[i] && ok[i+1] && pal(i,i+1)) {
				int low = 1, high = min(i - badL[i],badR[i+1] - i - 1), mid, ans = -1;
				while (low <= high) {
					mid = (low + high) / 2;
					if (pal(i - mid + 1, i + mid)) low = (ans = mid) + 1;
					else high = mid -1;
				}
				res += ans;
			}
		}
	}
	printf ("%lld\n",res);
    return 0;
}