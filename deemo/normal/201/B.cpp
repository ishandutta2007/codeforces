//We ain't ever getting older!

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 10;
const ll INF = 4e18;

int n, m, c[MAXN][MAXN];
ll ss[5 * MAXN];

ll get(int x, int y){
	if (x > n || y > m)	return INF;
	if (x < 0 || y < 0)	return INF;
	ll ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			ll dx = (i < x?(x - i - 1) * 4 + 2:(i-x) * 4 + 2);
			ll dy = (j < y?(y - j - 1) * 4 + 2:(j-y) * 4 + 2);
			ret += (ss[dx] + ss[dy]) * c[i][j];
		}
	return ret;
}

int main(){
	for (int i = 1; i < MAXN * 4; i++)	ss[i] = i * i;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &c[i][j]);

	int x = 0, y = 0;
	{
		int tl = -1, tr = n + 1;
		while (tr - tl > 1){
			int mid = tl + tr >> 1;
			if (get(mid, y) > get(mid + 1, y))
				tl = mid;
			else
				tr = mid;
		}
		x = tl + 1;
	}

	{
		int tl = -1, tr = m + 1;
		while (tr - tl > 1){
			int mid = tl + tr >> 1;
			if (get(x, mid) > get(x, mid + 1))
				tl = mid;
			else
				tr = mid;
		}
		y = tl + 1;
	}
	
	printf("%lld\n", get(x, y));
	printf("%d %d\n", x, y);
	return 0;
}