#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef pair<int, int>pii;
vector<int>pat[505050];
int main()
{
	int data;
	scanf("%d", &data);
	for (int p = 0; p < data; p++)
	{
		int num;
		scanf("%d", &num);
		for (int i = 0; i < num; i++)pat[i].clear();
		for (int i = 0; i < num - 1; i++)
		{
			int za, zb;
			scanf("%d%d", &za, &zb);
			za--, zb--;
			pat[za].push_back(zb), pat[zb].push_back(za);
		}
		string s;
		cin >> s;
		int rr = -1, r2 = -1;
		for (int i = 0; i < num; i++)
		{
			if (pat[i].size() >= 4)goto l01;
			else if (pat[i].size() >= 3)
			{
				if (rr != -1)
				{
					if (r2 != -1)goto l01;
					else r2 = i;
				}
				else rr = i;
			}
		}
		if (rr == -1)
		{
			if (num <= 2)goto l02;
			else if (num <= 3)
			{
				if ((s[0] == 'W') + (s[1] == 'W') + (s[2] == 'W') >= 2)goto l01;
				else goto l02;
			}
			else
			{
				int cnt = 0;
				for (int i = 0; i < num; i++)
				{
					if (pat[i].size() >= 3)abort();
					if (s[i] == 'W')
					{
						if (pat[i].size() >= 2)goto l01;
						else cnt++;
					}
				}
				if (cnt == 2 && num % 2 == 1)goto l01;
				else goto l02;
			}
		}
		else if (r2 == -1)
		{
			for (int i = 0; i < num; i++)
			{
				if (s[i] == 'W')
				{
					if (pat[i].size() >= 2)goto l01;
					if (pat[pat[i][0]].size() >= 3)goto l01;
				}
			}
			pii ls[10];
			for (int i = 0; i < 3; i++)
			{
				int bef = rr, now = pat[rr][i], cnt = 1;
				for (;;)
				{
					if (pat[now].size() == 1)break;
					cnt++;
					int zt = now;
					if (pat[now][0] == bef)now = pat[now][1];
					else now = pat[now][0];
					bef = zt;
				}
				ls[i] = make_pair(cnt, now);
			}
			sort(ls, ls + 3);
			if (ls[1].first >= 2)goto l01;
			if (s[ls[0].second] == 'W' || s[ls[1].second] == 'W')abort();
			if (s[ls[2].second] == 'W'&&num % 2 == 0)goto l01;
			else goto l02;
		}
		else
		{
			if (num % 2 == 1)goto l01;
			for (int i = 0; i < num; i++)
			{
				if (s[i] == 'W')goto l01;
			}
			int c = 0;
			for (int i = 0; i < 3; i++)
			{
				if (pat[pat[rr][i]].size() == 1)c++;
				if (pat[pat[r2][i]].size() == 1)c++;
			}
			if (c == 4)goto l02;
			else goto l01;
		}
		if (false)
		{
		l01:;
			printf("White\n");
		}
		if (false)
		{
		l02:;
			printf("Draw\n");
		}
	}
}