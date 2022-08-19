#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int l, n, a[100005];
int pos[100005], pot[100005];

bool checkm(int len)
{
	pos[n] = l;
	for(int i = n - 1; i >= 0; i --) {
		pos[i] = min(a[i], pos[i + 1] - len);
		if(pos[i] < (i == 0 ? 0 : a[i - 1])) return false;
	}
	return true;
}
bool checkx(int len)
{
	pot[n] = l;
	for(int i = n - 1; i >= 0; i --) {
		pot[i] = max(i == 0 ? 0 : a[i - 1], pot[i + 1] - len);
		if(pot[i] > a[i]) return false;
	}
	return pot[0] == 0;
}

int main()
{
	scanf("%d%d", &l, &n);
	rep(i, n) scanf("%d", &a[i]);
	int ml = 0, mr = l, xl = 0, xr = l;
	while(ml < mr) {
		int mid = (ml + mr + 1) >> 1;
		if(checkm(mid)) ml = mid;
		else mr = mid - 1;
	}
	checkm(ml);
	while(xl < xr) {
		int mid = (xl + xr) >> 1;
		if(checkx(mid)) xr = mid;
		else xl = mid + 1;
	}
	checkx(xl);
	
	int cur = 0;
	rep(i, n) {
		int nc = cur + ml;
		nc = min(nc, pos[i + 1]);
		nc = max(nc, pot[i + 1]);
		printf("%d %d\n", cur, nc);
		cur = nc;
	}
	return 0;
}