#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int tmax[21][1000003];
int tmin[21][1000003];
int kt[1000001];
typedef long double ld;
ld klg[1000001];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	vector<int>va, vb;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		va.push_back(z * 100);
		tmax[0][i] = z * 100;
	}
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vb.push_back(z);
		tmin[0][i] = z;
	}
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 0; j <= num - (1 << (i - 1)) + 1; j++)
		{
			tmax[i][j] = max(tmax[i - 1][j], tmax[i - 1][j + (1 << (i - 1))]);
			tmin[i][j] = min(tmin[i - 1][j], tmin[i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = 0;; j++)
		{
			if ((1 << j) > i)
			{
				kt[i] = j - 1;
				break;
			}
		}
	}
	vector<int>ans;
	for (int i = 0; i < num; i++)
	{
		int beg = i, end = num - 1;
		for (int p=0;p<30;p++)
		{
			int med = (beg + end + 1) / 2;
			int t = kt[med - i + 1];
			//printf("%d %d %d %d %d\n", beg, end, med, max(tmax[t][i], tmax[t][med - (1 << t) + 1]), min(tmin[t][i], tmin[t][med - (1 << t) + 1]));
			if (max(tmax[t][i], tmax[t][med - (1 << t) + 1])>min(tmin[t][i], tmin[t][med - (1 << t) + 1]))end = med - 1;
			else beg = med;
			if (beg == end)break;
		}
		int t1 = kt[beg - i + 1];
		int m1 = min(max(tmax[t1][i], tmax[t1][beg - (1 << t1) + 1]), min(tmin[t1][i], tmin[t1][beg - (1 << t1) + 1]));
		int t2 = kt[beg - i + 1 + 1];
		int m2 = min(max(tmax[t2][i], tmax[t2][beg - (1 << t2) + 2]), min(tmin[t2][i], tmin[t2][beg - (1 << t2) + 2]));
		ans.push_back(max(m1,m2));
		//printf("%d %d\n", beg,ans[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 1; i <= num; i++)klg[i] = klg[i - 1] + log((ld)i);
	ld ret = 0.0;
	for (int i = 0; i <= num - gen; i++)
	{
		ret += (ld)ans[i] * exp(klg[gen] + klg[num - gen] + klg[num - i - 1] - klg[num] - klg[gen - 1] - klg[num - i - gen]);
	}
	printf("%.20lf\n", double(ret));
}