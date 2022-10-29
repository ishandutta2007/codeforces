#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int num;
int query(int x1, int y1, int x2, int y2)
{
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return r;
}
vector<int>uni(vector<int>v)
{
	vector<int>r;
	int now = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (now != v[i])
		{
			now = v[i];
			r.push_back(now);
		}
	}
	return r;
}
int dat[4][4][4][4];
int main()
{
	scanf("%d", &num);
	vector<int>sx, sy;
	int beg, end;
	beg = 1, end = num;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end) / 2;
		if (query(1, 1, med, num) < 2)beg = med + 1;
		else end = med;
	}
	sx.push_back(beg);
	beg = 1, end = num;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end) / 2;
		if (query(1, 1, num, med) < 2)beg = med + 1;
		else end = med;
	}
	sy.push_back(beg);
	beg = 1, end = num;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end + 1) / 2;
		if (query(med, 1, num, num) < 2)end = med - 1;
		else beg = med;
	}
	sx.push_back(beg - 1);
	beg = 1, end = num;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end + 1) / 2;
		if (query(1, med, num, num) < 2)end = med - 1;
		else beg = med;
	}
	sy.push_back(beg - 1);
	beg = 1, end = num;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end) / 2;
		if (query(1, 1, med, num) < 1)beg = med + 1;
		else end = med;
	}
	sx.push_back(beg);
	beg = 1, end = num;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end) / 2;
		if (query(1, 1, num, med) < 1)beg = med + 1;
		else end = med;
	}
	sy.push_back(beg);
	beg = 1, end = num;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end + 1) / 2;
		if (query(med, 1, num, num) < 1)end = med - 1;
		else beg = med;
	}
	sx.push_back(beg - 1);
	beg = 1, end = num;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end + 1) / 2;
		if (query(1, med, num, num) < 1)end = med - 1;
		else beg = med;
	}
	sy.push_back(beg - 1);
	sort(sx.begin(), sx.end());
	sort(sy.begin(), sy.end());
	sx = uni(sx), sy = uni(sy);
	for (int i = 0; i < sx.size(); i++)
	{
		for (int j = 0; j < sy.size(); j++)
		{
			for (int k = i + 1; k < sx.size(); k++)
			{
				for (int l = j + 1; l < sy.size(); l++)
				{
					dat[i][j][k][l] = query(sx[i] + 1, sy[j] + 1, sx[k], sy[l]);
				}
			}
		}
	}
	for (int i1 = 0; i1 < sx.size(); i1++)
	{
		for (int j1 = 0; j1 < sy.size(); j1++)
		{
			for (int k1 = i1 + 1; k1 < sx.size(); k1++)
			{
				for (int l1 = j1 + 1; l1 < sy.size(); l1++)
				{
					for (int i2 = 0; i2 < sx.size(); i2++)
					{
						for (int j2 = 0; j2 < sy.size(); j2++)
						{
							for (int k2 = i2 + 1; k2 < sx.size(); k2++)
							{
								for (int l2 = j2 + 1; l2 < sy.size(); l2++)
								{
									bool f = true;
									for (int i = 0; i < sx.size(); i++)
									{
										for (int j = 0; j < sy.size(); j++)
										{
											for (int k = i + 1; k < sx.size(); k++)
											{
												for (int l = j + 1; l < sy.size(); l++)
												{
													int t = dat[i][j][k][l];
													int c = 0;
													if (sx[i] <= sx[i1] && sy[j] <= sy[j1] && sx[k1] <= sx[k] && sy[l1] <= sy[l])c++;
													if (sx[i] <= sx[i2] && sy[j] <= sy[j2] && sx[k2] <= sx[k] && sy[l2] <= sy[l])c++;
													if (c != t)f = false;
												}
											}
										}
									}
									if (f)
									{
										printf("! %d %d %d %d %d %d %d %d\n", sx[i1] + 1, sy[j1] + 1, sx[k1], sy[l1], sx[i2] + 1, sy[j2] + 1, sx[k2], sy[l2]);
										fflush(stdout);
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}