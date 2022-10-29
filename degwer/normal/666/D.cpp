#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int x[4], y[4];
int ansx[4], ansy[4];
int mini = 1000000000;
void get(vector<int>zx, vector<int>zy)
{
	bool fl = false;
	for (int i = 0; i < 4; i++)if (zx[i] != zx[0])fl = true;
	if (!fl)return;
	vector<int>v;
	for (int i = 0; i < 4; i++)v.push_back(i);
	for (;;)
	{
		int maxi = 0;
		for (int i = 0; i < 4; i++)
		{
			if (x[i] == zx[v[i]] || y[i] == zy[v[i]])
			{
				maxi = max(maxi, abs(x[i] - zx[v[i]]) + abs(y[i] - zy[v[i]]));
			}
			else maxi = 1000000000;
		}
		if (mini > maxi)
		{
			mini = maxi;
			for (int i = 0; i < 4; i++)ansx[i] = zx[v[i]], ansy[i] = zy[v[i]];
		}
		if (!next_permutation(v.begin(), v.end()))break;
	}
}
int main()
{
	int data;
	scanf("%d", &data);
	for (int p = 0; p < data; p++)
	{
		for (int i = 0; i < 4; i++)scanf("%d%d", &x[i], &y[i]);
		mini = 1000000000;
		for (int i = 1; i < 15; i++)
		{
			int v[4];
			for (int j = 0; j < 4; j++)v[j] = (0 != (i&(1 << j)));
			int rr;
			for (int j = 0; j < 4; j++)
			{
				int c = 0;
				for (int k = 0; k < 4; k++)if (v[j] != v[k])c++;
				if (c >= 2)rr = j;
			}
			vector<int>zx, zy;
			int c = 0;
			for (int j = 0; j < 4; j++)
			{
				if (v[rr] != v[j])
				{
					if (v[rr] == 0)
					{
						if (c < 2)
						{
							c++;
							zx.push_back(x[rr]);
							zy.push_back(y[j]);
						}
					}
					else
					{
						if (c < 2)
						{
							c++;
							zx.push_back(x[j]);
							zy.push_back(y[rr]);
						}
					}
				}
			}
			int dx = zx[1] - zx[0], dy = zy[1] - zy[0];
			zx.push_back(zx[0] + dy);
			zx.push_back(zx[1] + dy);
			zy.push_back(zy[0] + dx);
			zy.push_back(zy[1] + dx);
			get(zx, zy);
			zx.pop_back();
			zx.pop_back();
			zy.pop_back();
			zy.pop_back();
			zx.push_back(zx[0] - dy);
			zx.push_back(zx[1] - dy);
			zy.push_back(zy[0] - dx);
			zy.push_back(zy[1] - dx);
			get(zx, zy);
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					for (int l = 0; l < 4; l++)
					{
						int dx = x[j] - x[i];
						if (dx == 0)continue;
						vector<int>zx, zy;
						zx.push_back(x[i]);
						zx.push_back(x[i]);
						zx.push_back(x[j]);
						zx.push_back(x[j]);
						int ny = (y[k] + y[l]) / 2;
						zy.push_back(ny);
						zy.push_back(ny + dx);
						zy.push_back(ny);
						zy.push_back(ny + dx);
						get(zx, zy);
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						ny = (y[k] + y[l] + 1) / 2;
						zy.push_back(ny);
						zy.push_back(ny + dx);
						zy.push_back(ny);
						zy.push_back(ny + dx);
						get(zx, zy);
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						ny = (y[k] + y[l] - dx) / 2;
						zy.push_back(ny);
						zy.push_back(ny + dx);
						zy.push_back(ny);
						zy.push_back(ny + dx);
						get(zx, zy);
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						ny = (y[k] + y[l] - dx + 1) / 2;
						zy.push_back(ny);
						zy.push_back(ny + dx);
						zy.push_back(ny);
						zy.push_back(ny + dx);
						get(zx, zy);
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						ny = (y[k] + y[l] - dx - dx) / 2;
						zy.push_back(ny);
						zy.push_back(ny + dx);
						zy.push_back(ny);
						zy.push_back(ny + dx);
						get(zx, zy);
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						ny = (y[k] + y[l] - dx - dx + 1) / 2;
						zy.push_back(ny);
						zy.push_back(ny + dx);
						zy.push_back(ny);
						zy.push_back(ny + dx);
						get(zx, zy);
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
						zy.pop_back();
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					for (int l = 0; l < 4; l++)
					{
						int dy = y[j] - y[i];
						if (dy == 0)continue;
						vector<int>zx, zy;
						zy.push_back(y[i]);
						zy.push_back(y[i]);
						zy.push_back(y[j]);
						zy.push_back(y[j]);
						int nx = (x[k] + x[l]) / 2;
						zx.push_back(nx);
						zx.push_back(nx + dy);
						zx.push_back(nx);
						zx.push_back(nx + dy);
						get(zx, zy);
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						nx = (x[k] + x[l] + 1) / 2;
						zx.push_back(nx);
						zx.push_back(nx + dy);
						zx.push_back(nx);
						zx.push_back(nx + dy);
						get(zx, zy);
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						nx = (x[k] + x[l] - dy) / 2;
						zx.push_back(nx);
						zx.push_back(nx + dy);
						zx.push_back(nx);
						zx.push_back(nx + dy);
						get(zx, zy);
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						nx = (x[k] + x[l] - dy + 1) / 2;
						zx.push_back(nx);
						zx.push_back(nx + dy);
						zx.push_back(nx);
						zx.push_back(nx + dy);
						get(zx, zy);
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						nx = (x[k] + x[l] - dy - dy) / 2;
						zx.push_back(nx);
						zx.push_back(nx + dy);
						zx.push_back(nx);
						zx.push_back(nx + dy);
						get(zx, zy);
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						nx = (x[k] + x[l] - dy - dy + 1) / 2;
						zx.push_back(nx);
						zx.push_back(nx + dy);
						zx.push_back(nx);
						zx.push_back(nx + dy);
						get(zx, zy);
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
						zx.pop_back();
					}
				}
			}
		}
		if (mini == 1000000000)printf("-1\n");
		else
		{
			printf("%d\n", mini);
			for (int i = 0; i < 4; i++)printf("%d %d\n", ansx[i], ansy[i]);
		}
	}
}