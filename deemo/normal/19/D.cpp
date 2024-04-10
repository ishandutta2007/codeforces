#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int INF = 1e9;

int n, x[MAXN], y[MAXN], secx[MAXN], sx, secy[MAXN], sy;
short type[MAXN];
char ch[8];
multiset<int>	ss[MAXN];
int weed[4 * MAXN];

void water(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		weed[v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	if (pos < mid)
		water(v<<1, b, mid, pos, val);
	else
		water(v<<1^1, mid, e, pos, val);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

int	smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return -INF;

	int mid = (b + e)/ 2;
	return max(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", ch);
		if (ch[0] == 'a')
			type[i] = 0;
		else if (ch[0] == 'r')
			type[i] = 1;
		else
			type[i] = 2;

		scanf("%d %d", &x[i], &y[i]);
		secx[sx++] = x[i];
		secy[sy++] = y[i];
	}
	sort(secx, secx + sx);
	sx = unique(secx, secx + sx) - secx;
	for (int i = 0; i < n; i++)
		x[i] = lower_bound(secx, secx + sx, x[i]) - secx;

	sort(secy, secy + sy);
	sy = unique(secy, secy + sy) - secy;
	for (int i = 0; i < n; i++)
		y[i] = lower_bound(secy, secy + sy, y[i]) - secy;

	for (int i = 0; i < n; i++){
		if (type[i] == 0){
			ss[x[i]].insert(y[i]);
			auto it = ss[x[i]].end();
			it--;
			water(1, 0, sx, x[i], *it);
		}
		else if (type[i] == 1){
			ss[x[i]].erase(ss[x[i]].find(y[i]));
			auto it = ss[x[i]].end();
			if (it == ss[x[i]].begin())
				water(1, 0, sx, x[i], -INF);
			else
				it--, water(1, 0, sx, x[i], *it);
		}
		else{
			if (x[i] == sx - 1){
				printf("-1\n");
				continue;
			}

			int v = 1, b = 0, e = sx;
			while (e - b > 1){
				int mid = (b + e)/ 2;
				if (smoke(v<<1, b, mid, x[i] + 1, sx) > y[i])
					v = v<<1, e = mid;
				else
					v = v<<1^1, b = mid;
			}
			auto it = ss[b].upper_bound(y[i]);
			if (it == ss[b].end())
				printf("-1\n");
			else
				printf("%d %d\n", secx[b], secy[*it]);
		}
	}
	return 0;
}