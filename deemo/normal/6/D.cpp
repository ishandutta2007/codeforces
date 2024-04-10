#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 15 + 4;

int n, a, b, h[MAXN], cnt[MAXN];
int d[MAXN][MAXN][MAXN][MAXN];
pair<pair<int, int>, pair<int, int>>	par[MAXN][MAXN][MAXN][MAXN];

int add(int x, int y){return max(0, x+y);}

void update(int dd, int i, int x, int y, int z, pair<pair<int, int>, pair<int, int>> p){
	if (d[i][x][y][z] > dd)
		d[i][x][y][z] = dd, par[i][x][y][z] = p;
}

int main(){
	memset(d, 63, sizeof(d));
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)	cin >> h[i], h[i]++;
	while (h[0])
		h[0] = add(h[0], -b), h[1] = add(h[1], -a), h[2] = add(h[2], -b), cnt[1]++;
	while (h[n - 1])
		h[n - 1] = add(h[n - 1], -b), h[n - 2] = add(h[n - 2], -a), h[n - 3] = add(h[n - 3], -b), cnt[n-2]++;

	d[0][h[0]][h[1]][h[2]] = cnt[1] + (n>3?cnt[n - 2]:0);
	for (int i = 0; i < n; i++)
		for (int x = h[i]; ~x; x--)
			for (int y = h[i + 1]; ~y; y--)
				for (int z = h[i + 2]; ~z; z--)
					if (!x)
						update(d[i][x][y][z], i + 1, y, z, h[i + 3], {{x, y}, {z, 3}});
					else{
						update(d[i][x][y][z] + 1, i, add(x, -a), add(y, -b), z, {{x, y}, {z, 1}});
						update(d[i][x][y][z] + 1, i, add(x, -b), add(y, -a), add(z, -b), {{x, y}, {z, 2}});
					}

	cout << d[n-1][0][0][0] << "\n";
	int i = n-1, x = 0, y = 0, z = 0;
	while (par[i][x][y][z].S.S){
		auto p = par[i][x][y][z];
		if (p.S.S == 3)
			i--, x = p.F.F, y = p.F.S, z = p.S.F;
		else if (p.S.S == 2)
			x = p.F.F, y = p.F.S, z = p.S.F, cnt[i+1]++;
		else
			x = p.F.F, y = p.F.S, z = p.S.F, cnt[i]++;
	}

	for (int i = 0; i < n; i++)
		while (cnt[i]--)
			cout << i + 1 << " ";
	cout << "\n";
	return 0;
}