#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n;
int mx[100005], mn[100005];
bool hv[100005];
int cmx[100005], cmn[100005], cnt;

int main()
{
	scanf("%d", &n);
	rep(i, n) {
		int l, x;
		scanf("%d", &l);
		mn[i] = INF;
		mx[i] = -INF;
		hv[i] = false;
		rep(j, l) {
			scanf("%d", &x);
			if(mn[i] < x) hv[i] = true;
			mn[i] = min(mn[i], x);
			mx[i] = max(mx[i], x);
		}
	}
	
	LL ans = 1LL * n * n;
	rep(i, n) if(!hv[i]) {
		cmn[cnt] = mn[i];
		cmx[cnt] = mx[i];
		cnt ++;
	}
	
	sort(cmx, cmx + cnt);
	rep(i, cnt) ans -= upper_bound(cmx, cmx + cnt, cmn[i]) - cmx;
	printf("%lld\n", ans); 
	return 0;
}