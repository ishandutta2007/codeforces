#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll l[500001], r[500001], u[500001], d[500001];
typedef pair<ll, ll>pii;
int main()
{
	int len;
	ll mx, my;
	scanf("%d%I64d%I64d", &len, &mx, &my);
	string str;
	cin >> str;
	int nx = 0, ny = 0;
	int ptl = 0, ptr = 0, ptu = 0, ptd = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'L')ny--;
		if (str[i] == 'R')ny++;
		if (str[i] == 'U')nx--;
		if (str[i] == 'D')nx++;
		if (nx > ptd)
		{
			ptd++;
			d[ptd] = i + 1;
		}
		if (-nx > ptu)
		{
			ptu++;
			u[ptu] = i + 1;
		}
		if (ny > ptr)
		{
			ptr++;
			r[ptr] = i + 1;
		}
		if (-ny > ptl)
		{
			ptl++;
			l[ptl] = i + 1;
		}
	}
	if (nx > 0)
	{
		for (int i = ptd + 1; i <= 500000; i++)d[i] = d[i - nx] + len;
		ptd = 500000;
	}
	if (-nx > 0)
	{
		for (int i = ptu + 1; i <= 500000; i++)u[i] = u[i + nx] + len;
		ptu = 500000;
	}
	if (ny > 0)
	{
		for (int i = ptr + 1; i <= 500000; i++)r[i] = r[i - ny] + len;
		ptr = 500000;
	}
	if (-ny > 0)
	{
		for (int i = ptl + 1; i <= 500000; i++)l[i] = l[i + ny] + len;
		ptl = 500000;
	}
	vector<pii>vec;
	for (int i = 1; i <= ptd; i++)vec.push_back(make_pair(d[i], 0));
	for (int i = 1; i <= ptu; i++)vec.push_back(make_pair(u[i], 0));
	for (int i = 1; i <= ptr; i++)vec.push_back(make_pair(r[i], 1));
	for (int i = 1; i <= ptl; i++)vec.push_back(make_pair(l[i], 1));
	sort(vec.begin(), vec.end());
	ll ans = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (mx == 0 || my == 0)break;
		if (vec[i].second == 0)
		{
			ans += my*vec[i].first;
			mx--;
		}
		else
		{
			ans += mx*vec[i].first;
			my--;
		}
		ans %= 1000000007;
	}
	if (mx != 0 && my != 0)
	{
		printf("-1\n");
	}
	else printf("%I64d\n", ans);
}