#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int ans[1 << 20];
int dat[1 << 20][50];
typedef pair<char, int>pci;
pci ord[20][50];
typedef long double ld;
ld kai[30];
int main()
{
	int num;
	scanf("%d", &num);
	if (num == 1)
	{
		printf("0\n");
		return 0;
	}
	vector<string>vec;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
		for (int j = 0; j < s.size(); j++)
		{
			ord[j][i] = make_pair(s[j], i);
		}
	}
	int len = vec[0].size();
	for (int i = 0; i < len; i++)sort(ord[i], ord[i] + num);
	kai[0] = 1;
	for (int i = 1; i < 30; i++)kai[i] = kai[i - 1] * i;
	for (int p = 1; p < (1 << len); p++)
	{
		int bef, rr;
		for (int i = 0; i < len; i++)
		{
			if (p&(1 << i))
			{
				bef = p - (1 << i);
				rr = i;
				break;
			}
		}
		int now[50];
		char nl[50];
		int pt = 0;
		fill(nl, nl + 50, '0');
		for (int i = 0; i < num; i++)
		{
			if (nl[dat[bef][ord[rr][i].second]] != ord[rr][i].first)
			{
				dat[p][ord[rr][i].second] = pt;
				now[dat[bef][ord[rr][i].second]] = pt++;
				nl[dat[bef][ord[rr][i].second]] = ord[rr][i].first;
			}
			else
			{
				dat[p][ord[rr][i].second] = now[dat[bef][ord[rr][i].second]];
			}
		}
		int cnt[50];
		fill(cnt, cnt + 50, 0);
		for (int i = 0; i < num; i++)cnt[dat[p][i]]++;
		for (int i = 0; i < pt; i++)ans[p] += (cnt[i] == 1);
	}
	ld ret = 0;
	for (int p = 0; p < (1 << len); p++)
	{
		//printf("%d: %d\n", p, ans[p]);
		//for (int i = 0; i < num; i++)printf("%d ", dat[p][i]); printf("\n");
		int c = 0;
		for (int i = 0; i < len; i++)if (p&(1 << i))c++;
		for (int i = 0; i < len; i++)
		{
			if ((p&(1 << i)) == 0)
			{
				ret += kai[len - c - 1] * (ans[p + (1 << i)] - ans[p]) * (c + 1) * kai[c] / num / kai[len];
			}
		}
	}
	printf("%.20Lf\n", ret);
}