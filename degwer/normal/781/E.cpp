#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 131072
typedef long long ll;
typedef pair<ll, ll>pii;
#define INF 1000000000000000000LL
class segtree
{
public:
	ll seg[SIZE * 2];
	int idx[SIZE * 2];
	void update(int a, ll b)
	{
		a += SIZE;
		seg[a] = b;
		idx[a] = a - SIZE;
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = min(seg[a * 2], seg[a * 2 + 1]);
			if (seg[a * 2] < seg[a * 2 + 1])idx[a] = idx[a * 2];
			else idx[a] = idx[a * 2 + 1];
		}
	}
	pii get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return make_pair(INF, -1);
		if (beg <= lb&&ub <= end)return make_pair(seg[node], idx[node]);
		return min(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree tree;
typedef pair<pii, pii>pi4;
vector<pii>now[100000];
ll mod = 1000000007;
int main()
{
	int hei, col, num;
	scanf("%d%d%d", &hei, &col, &num);
	for (int i = 0; i < col; i++)now[i].push_back(make_pair(INF, 0LL)), now[i].push_back(make_pair(hei + 1, 1LL));
	for (int i = 0; i < col; i++)tree.update(i, hei + 1);
	vector<pi4>qs;
	for (int i = 0; i < num; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		zb--, zc--;
		qs.push_back(make_pair(make_pair(za, zd), make_pair(zb, zc)));
	}
	sort(qs.begin(), qs.end());
	reverse(qs.begin(), qs.end());
	for (int i = 0; i < qs.size(); i++)
	{
		ll sum = 0;
		for (;;)
		{
			pii z = tree.get(qs[i].second.first, qs[i].second.second, 1, 0, SIZE - 1);
			if (z.first > qs[i].first.first + qs[i].first.second)break;
			sum += now[z.second][now[z.second].size() - 1].second;
			now[z.second].pop_back();
			tree.update(z.second, now[z.second][now[z.second].size() - 1].first);
		}
		sum %= mod;
		ll a = qs[i].second.first - 1, b = qs[i].second.second + 1;
		if (a < 0)a = b;
		if (b >= col)b = a;
		now[a].push_back(make_pair(qs[i].first.first, sum));
		tree.update(a, qs[i].first.first);
		now[b].push_back(make_pair(qs[i].first.first, sum));
		tree.update(b, qs[i].first.first);
	}
	ll ans = 0;
	for (int i = 0; i < col; i++)for (int j = 0; j < now[i].size(); j++)ans += now[i][j].second;
	printf("%I64d\n", ans%mod);
}