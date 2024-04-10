#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;
const int MAXK = 20 + 1;

int n, k, l, vec[MAXK], sz;
bool mark[MAXN];
int lv[MAXN], d[1<<MAXK], q[MAXN], y[MAXN], w[MAXK][MAXK];

bool fit(int x){return 0 <= x && x <= n;}

int main(){
	scanf("%d %d %d", &n, &k, &l); 
	for (int i = 0; i < k; i++){
		int x;	scanf("%d", &x), x--;
		mark[x] = 1;
	}
	for (int i = 0; i + 1 < MAXN; i++)
		if (i && mark[i - 1] && !mark[i])
			vec[sz++] = i;
		else if (mark[i] && (!i || !mark[i - 1]))
			vec[sz++] = i;

	for (int i = 0; i < l; i++)
		scanf("%d", &y[i]);

	for (int i = 0; i < sz; i++){
		memset(lv, 63, sizeof(lv));
		int h = 0, t = 0;
		q[t++] = vec[i];
		lv[vec[i]] = 0;
		while (h < t){
			int v = q[h++];
			for (int i = 0; i < l; i++){
				if (fit(v + y[i]) && lv[v] + 1 < lv[v + y[i]])	lv[v + y[i]] = lv[v] + 1, q[t++] = v + y[i];
				y[i] = -y[i];
				if (fit(v + y[i]) && lv[v] + 1 < lv[v + y[i]])	lv[v + y[i]] = lv[v] + 1, q[t++] = v + y[i];
				y[i] = -y[i];
			}
		}
		for (int j = 0; j < sz; j++)
			if (i^j)
				w[i][j] = lv[vec[j]];
	}

	memset(d, 63, sizeof(d));
	d[0] = 0;
	for (int i = 1; i < 1<<sz; i++){
		int t = __builtin_popcount(i);
		if (t&1)	continue;
		int v = __builtin_ctz(i&-i);
		for (int j = v + 1; j < sz; j++)
			if (i>>j&1)
				d[i] = min(d[i], d[i^1<<v^1<<j] + w[v][j]);
	}	

	if (d[(1<<sz)-1] < 1e9)
		printf("%d\n", d[(1<<sz)-1]);
	else
		printf("-1\n");
	return 0;
}