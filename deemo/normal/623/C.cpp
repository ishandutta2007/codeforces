//One last time..

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const ll INF = 1e18;
const int LOG = 17;

ll ans = INF, lmn[MAXN], lmx[MAXN], rmn[MAXN], rmx[MAXN];
ll st[LOG + 2][MAXN];
int n, save[MAXN];
pair<ll, ll>	p[MAXN];

void init(){
	for (int i = 0; i < n - 1; i++)
		st[0][i] = p[i].first * p[i].first + max(abs(rmx[i + 1]), abs(rmn[i + 1])) * max(abs(rmx[i + 1]), abs(rmn[i + 1]));
	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < n; i++)
			if (i + (1<<(w - 1)) >= n)
				st[w][i] = st[w - 1][i];
			else
				st[w][i] = min(st[w - 1][i], st[w - 1][i + (1<<(w-1))]);
	
	for (int i = 1, j = 0; i < MAXN; i += (1<<j), j++)
		for (int w = i; w < MAXN && w < i + (1<<j); w++)	save[w] = j;
}

bool ok(int ind, ll mid){
	if (ind && (lmx[ind] - lmn[ind]) * (lmx[ind] - lmn[ind]) > mid)	return false;
	if (ind && mid < p[ind].first * p[ind].first + max(abs(lmx[ind]), abs(lmn[ind])) * max(abs(lmx[ind]), abs(lmn[ind])))	return	false;
	
	int r = n;
	for (int w = LOG; w >= 0; w--)
		if (r - (1<<w) >= ind){
			if ((p[ind].first - p[r - (1<<w)].first) * (p[ind].first - p[r - (1<<w)].first) > mid)	goto tof;
			if (ind && max(abs(lmx[ind]), abs(lmn[ind])) * max(abs(lmx[ind]), abs(lmn[ind])) + p[r - (1<<w)].first * p[r - (1<<w)].first > mid)	goto tof;
			continue;
tof:
			r -= (1<<w);
		}

	int l = ind - 1;
	for (int w = LOG; w >= 0; w--)
		if (l + (1<<w) < r){
			if (ind && l + (1 << w) + 1 < n){
				ll mm = max(rmx[l + (1<<w) + 1], lmx[ind]);
				ll nn = min(rmn[l + (1<<w) + 1], lmn[ind]);
				if ((mm - nn) * (mm - nn) > mid)	goto tof2;
			}
			if (l + (1<<w) + 1 < n){
				ll mm = rmx[l + (1<<w) + 1];
				ll nn = rmn[l + (1<<w) + 1];
				if ((mm - nn) * (mm - nn) > mid)	goto tof2;
			}
			if (l + (1<<w) + 1 < n && p[ind].first * p[ind].first + max(abs(rmx[l + (1<<w) + 1]), abs(rmn[l + (1<<w) + 1])) * max(abs(rmx[l + (1<<w) + 1]), abs(rmn[l + (1<<w) + 1])) > mid)	goto tof2;
			continue;
tof2:
			l += (1<<w);
		}
	l++;
	if (l < r)
		return	min(st[save[r - l]][l], st[save[r - l]][r - (1<<save[r - l])]) <= mid;
	return	false;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%I64d %I64d", &p[i].first, &p[i].second);
	if (n == 1){printf("0\n"); return 0;}

	sort(p, p + n);
	lmn[0] = INF, lmx[0] = -INF;
	for (int i = 0; i < n; i++)
		lmn[i + 1] = min(lmn[i], p[i].second), lmx[i + 1] = max(lmx[i], p[i].second);
	lmn[0] = 0, lmx[0] = 1e7;
	rmn[n] = INF, rmx[n] = -INF;
	for (int i = n - 1; i >= 0; i--)
		rmn[i] = min(rmn[i + 1], p[i].second), rmx[i] = max(rmx[i + 1], p[i].second);
	rmn[n] = 0, rmx[n] = 1e7;
	init();

	for (int i = 0; i < n; i++){
		ll b = 0, e = 1e17, ret = 1e17;
		while (b <= e){
			ll mid = (b + e)/ 2;
			if (ok(i, mid))
				ret = mid, e = mid - 1;
			else
				b = mid + 1;
		}
		ans = min(ans, ret);
	}
	ans = min(ans, (lmx[n] - lmn[n]) * (lmx[n] - lmn[n]));
	ans = min(ans, (p[n - 1].first - p[0].first) * (p[n - 1].first - p[0].first));
	printf("%I64d\n", ans);
	return	0;
}