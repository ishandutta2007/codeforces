#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
ll det(pii a, pii b)
{
	return a.first*b.second - a.second*b.first;
}
int ccw(pii a, pii b, pii c)
{
	ll t = det(make_pair(b.first - a.first, b.second - a.second), make_pair(c.first - a.first, c.second - a.second));
	if (t < 0)return -1;
	if (t == 0)return 0;
	return 1;
}
int cdet(pii a, pii b)
{
	if (det(a, b) < 0)return -1;
	if (det(a, b) == 0)return 0;
	return 1;
}
vector<pii>conv;
pii get(int a)
{
	return make_pair(conv[(a + conv.size() - 1) % conv.size()].first - conv[a].first, conv[(a + conv.size() - 1) % conv.size()].second - conv[a].second);
}
bool isval(int a, int b, int c)
{
	if (a == b || b == c || c == a)return false;
	pii v1 = make_pair(conv[c].first - conv[b].first, conv[c].second - conv[b].second);
	pii v2 = make_pair(conv[a].first - conv[c].first, conv[a].second - conv[c].second);
	pii v3 = make_pair(conv[b].first - conv[a].first, conv[b].second - conv[a].second);
	if (cdet(v1, get(a)) == cdet(v1, get((a + 1) % conv.size())))return false;
	if (cdet(v2, get(b)) == cdet(v2, get((b + 1) % conv.size())))return false;
	if (cdet(v3, get(c)) == cdet(v3, get((c + 1) % conv.size())))return false;
	return true;
}
int main()
{
	int num;
	ll men;
	scanf("%d%I64d", &num, &men);
	vector<pii>vec;
	for (int i = 0; i < num; i++)
	{
		ll za, zb;
		scanf("%I64d%I64d", &za, &zb);
		vec.push_back(make_pair(za, zb));
	}
	sort(vec.begin(), vec.end());
	vector<pii>c1, c2;
	c1.push_back(vec[0]);
	for (int i = 1; i < num; i++)
	{
		for (;;)
		{
			if (c1.size() <= 1)break;
			pii a = c1[c1.size() - 2], b = c1[c1.size() - 1];
			if (ccw(a, b, vec[i]) != 1)c1.pop_back();
			else break;
		}
		c1.push_back(vec[i]);
	}
	c2.push_back(vec[0]);
	for (int i = 1; i < num; i++)
	{
		for (;;)
		{
			if (c2.size() <= 1)break;
			pii a = c2[c2.size() - 2], b = c2[c2.size() - 1];
			if (ccw(a, b, vec[i]) != -1)c2.pop_back();
			else break;
		}
		c2.push_back(vec[i]);
	}
	for (int i = 0; i < c1.size() - 1; i++)conv.push_back(c1[i]);
	for (int i = c2.size() - 1; i >= 1; i--)conv.push_back(c2[i]);
	num = conv.size();
	for (int i = 0; i < num; i++)
	{
		int now = (i + 2) % num;
		for (int j = 1; j < num - 1; j++)
		{
			int t = (i + j) % num;
			for (;;)
			{
				if ((now + 1) % num == i)break;
				pii v = make_pair(conv[i].first - conv[t].first, conv[i].second - conv[t].second);
				if (cdet(v, get(now)) == cdet(v, get((now + 1) % conv.size())))
				{
					now++;
					now %= num;
				}
				else break;
			}
			if (isval(i, t, now))
			{
				printf("%I64d %I64d\n", conv[i].first + conv[t].first - conv[now].first, conv[i].second + conv[t].second - conv[now].second);
				printf("%I64d %I64d\n", conv[i].first - conv[t].first + conv[now].first, conv[i].second - conv[t].second + conv[now].second);
				printf("%I64d %I64d\n", -conv[i].first + conv[t].first + conv[now].first, -conv[i].second + conv[t].second + conv[now].second);
				return 0;
			}
			if (isval(i, t, (now + 1) % conv.size()))
			{
				now = (now + 1) % conv.size();
				printf("%I64d %I64d\n", conv[i].first + conv[t].first - conv[now].first, conv[i].second + conv[t].second - conv[now].second);
				printf("%I64d %I64d\n", conv[i].first - conv[t].first + conv[now].first, conv[i].second - conv[t].second + conv[now].second);
				printf("%I64d %I64d\n", -conv[i].first + conv[t].first + conv[now].first, -conv[i].second + conv[t].second + conv[now].second);
				return 0;
			}
		}
	}
}