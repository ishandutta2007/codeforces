#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int p[2][N];
int siz[2][N];

int get(int x, int c)
{
	if(p[c][x] == x)
		return x;
	return p[c][x] = get(p[c][x], c);
}

void merge(int x, int y, int c)
{
	x = get(x, c);
	y = get(y, c);
	if(siz[c][x] < siz[c][y])
		swap(x, y);
	p[c][y] = x;
	siz[c][x] += siz[c][y];
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		p[0][i] = p[1][i] = i;
		siz[0][i] = siz[1][i] = 1;
	}
	for(int i = 0; i < n - 1; i++)
	{
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		--x;
		--y;
		merge(x, y, c);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(p[0][i] == i)
			ans += siz[0][i] * 1ll * (siz[0][i] - 1);
		if(p[1][i] == i)
			ans += siz[1][i] * 1ll * (siz[1][i] - 1);
		ans += (siz[0][get(i, 0)] - 1) * 1ll * (siz[1][get(i, 1)] - 1);
	}
	cout << ans << endl;
}