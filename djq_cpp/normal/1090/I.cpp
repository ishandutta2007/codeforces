#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int perm[20000005];

void rsort(int n, int dat[]) {
    const int S = 8;
    static int _b[20000005], *a, *b;
    static int cnt[256];
    int i;
    a = perm + 1;
    b = _b;
    for (i = 0; i < 32; i += S) {
        for (int j = 0; j < 256; j++) cnt[j] = 0;
        if (i + S >= 32) {
            for (int j = 0; j < n; j++) ++cnt[dat[a[j]] >> i];
            for (int j = 1; j < 1 << S; j++) cnt[j] += cnt[j - 1];
            for (int j = n - 1; j >= 0; j--) b[--cnt[dat[a[j]] >> i]] = a[j];
            int *tmp = a;
            a = b, b = tmp;
            continue;
        }
        int t = (1 << S) - 1;
        for (int j = 0; j < n; j++) ++cnt[(dat[a[j]] >> i) & t];
        for (int j = 1; j < 1 << S; j++) cnt[j] += cnt[j - 1];
        for (int j = n - 1; j >= 0; j--) b[--cnt[(dat[a[j]] >> i) & t]] = a[j];
        int *tmp = a;
        a = b, b = tmp;
    }
}

int pre[20000005], nxt[20000005];

LL solve_d(int n, int dat[])
{
	LL ans = INF;
	bool hvn = false, hvp = false;
	rep1(i, n) if(dat[i] < 0) hvn = true;
	else if(dat[i] > 0) hvp = true;
	
	if(hvn && hvp) {
		int cur = 0;
		rep1(i, n) if(dat[i] < 0) cur = min(cur, dat[i]);
		else ans = min(ans, 1LL * cur * dat[i]);
		
		if(ans >= 0) rep1(i, n)
		if(dat[i] < 0) return min(solve_d(i - 1, dat), solve_d(n - i + 1, dat + i - 1));
		
		return ans;
	} else if(hvn) {
		rep1(i, n) dat[i] *= -1;
		reverse(dat + 1, dat + n + 1);
	}
	
	int cmin = dat[1];
	for(int i = 2; i <= n; i ++) {
		if(cmin < dat[i]) ans = min(ans, 1LL * dat[i] * cmin);
		cmin = min(cmin, dat[i]);
	}
	return ans; 
}

unsigned int b[20000005];
int n, dat[20000005];
LL ans;
void solve_d()
{
	int l, r, x, y, z;
	scanf("%d%d%d%d%d%d%u%u", &n, &l, &r, &x, &y, &z, &b[1], &b[2]);
	for(int i = 3; i <= n; i ++) b[i] = b[i - 2] * x + b[i - 1] * y + z;
	rep1(i, n) dat[i] = l + b[i] % (1LL * r - l + 1);
	ans = solve_d(n, dat);
	if(ans != INF) printf("%I64d\n", ans);
	else printf("IMPOSSIBLE\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve_d();
	return 0;
}