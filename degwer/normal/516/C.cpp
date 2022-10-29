#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define SIZE 262144
class segtree
{
public:
	pii seg[SIZE * 2];
	void update(ll a, ll b)
	{
		a += SIZE;
		seg[a] = max(seg[a], make_pair(b, a - SIZE));
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = max(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	pii get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return make_pair(0, 0);
		if (beg <= lb&&ub <= end)return seg[node];
		return max(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree t1, t2;
ll dist[100000];
ll hei[100000];
ll rui[100001];
int num, query;
ll getd(ll a, ll b)
{
	if (a < b)return rui[b] - rui[a];
	else return rui[b] + rui[num] - rui[a];
}
int main()
{
	scanf("%d%d", &num, &query);
	for (int i = 0; i < num; i++)scanf("%I64d", &dist[i]);
	for (int i = 0; i < num; i++)scanf("%I64d", &hei[i]);
	for (int i = 0; i < num; i++)rui[i + 1] = rui[i] + dist[i];
	for (int i = 0; i < num; i++)
	{
		t1.update(i, hei[i] * 2 + getd(i, 0) + rui[num]);
		t1.update(i + num, hei[i] * 2 + getd(i, 0));
		if (i != 0)
		{
			t2.update(i, hei[i] * 2 + getd(0, i));
			t2.update(i + num, hei[i] * 2 + getd(0, i) + rui[num]);
		}
		else
		{
			t2.update(i, hei[i] * 2);
			t2.update(i + num, hei[i] * 2 + rui[num]);
		}
	}
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		int s = (zb + 1) % num, t = (za + num - 1) % num;
		if (s > t)t += num;
		pii a1 = t1.get(s, t, 1, 0, SIZE - 1), a2 = t2.get(s, t, 1, 0, SIZE - 1);
		if (a1.second == a2.second)
		{
			pii b1 = t1.get(s, a1.second - 1, 1, 0, SIZE - 1), b2 = t2.get(a1.second + 1, t, 1, 0, SIZE - 1);
			printf("%I64d\n", max(b1.first + a2.first, a1.first + b2.first) - rui[num] * 2);
		}
		else printf("%I64d\n", a1.first + a2.first - rui[num] * 2);
	}
}