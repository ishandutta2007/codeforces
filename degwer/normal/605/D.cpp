#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
#define SIZE 262144
typedef pair<int, int>pii;
int dx[100001];
int dy[100001];
int tx[100001];
int ty[100001];
class segtree
{
public:
	set<pii>seg[SIZE * 2];
	vector<pii>z;
	void init(vector<pii>vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			int now = vec[i].first + SIZE;
			for (;;)
			{
				seg[now].insert(make_pair(vec[i].second, i));
				now /= 2;
				if (now == 0)break;
			}
		}
	}
	void remove(pii x, int n)
	{
		int now = x.first + SIZE;
		for (;;)
		{
			seg[now].erase(make_pair(x.second, n));
			now /= 2;
			if (now == 0)break;
		}
	}
	int get(int ex, int ey, int node, int lx, int ux)
	{
		if (ex < lx)return -1;
		if (ux <= ex)
		{
			if (seg[node].empty())return -1;
			set<pii>::iterator it = seg[node].begin();
			if ((*it).first <= ey)
			{
				return (*it).second;
			}
			else return -1;
		}
		return max(get(ex, ey, node * 2, lx, (lx + ux) / 2), get(ex, ey, node * 2 + 1, (lx + ux) / 2 + 1, ux));
	}
	vector<int>calc(int ex, int ey)
	{
		vector<int>ret;
		for (;;)
		{
			int t = get(ex, ey, 1, 0, SIZE - 1);
			if (t == -1)return ret;
			ret.push_back(t);
			remove(make_pair(dx[t], dy[t]), t);
		}
	}
};
segtree tree;
vector<int>uni(vector<int>v)
{
	int now = -1;
	vector<int>ret;
	for (int i = 0; i < v.size(); i++)
	{
		if (now != v[i])
		{
			now = v[i];
			ret.push_back(now);
		}
	}
	return ret;
}
int dist[100001];
int frm[100001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>zx, zy;
	zx.push_back(0);
	zy.push_back(0);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d%d%d%d", &dx[i], &dy[i], &tx[i], &ty[i]);
		zx.push_back(dx[i]);
		zy.push_back(dy[i]);
		zx.push_back(tx[i]);
		zy.push_back(ty[i]);
	}
	sort(zx.begin(), zx.end());
	sort(zy.begin(), zy.end());
	zx = uni(zx);
	zy = uni(zy);
	for (int i = 0; i <= num; i++)
	{
		dx[i] = lower_bound(zx.begin(), zx.end(), dx[i]) - zx.begin();
		dy[i] = lower_bound(zy.begin(), zy.end(), dy[i]) - zy.begin();
		tx[i] = lower_bound(zx.begin(), zx.end(), tx[i]) - zx.begin();
		ty[i] = lower_bound(zy.begin(), zy.end(), ty[i]) - zy.begin();
		//printf("  %d %d %d %d\n", dx[i], dy[i], tx[i], ty[i]);
	}
	vector<pii>zz;
	for (int i = 0; i <= num; i++)zz.push_back(make_pair(dx[i], dy[i]));
	tree.init(zz);
	queue<pii>que;
	que.push(make_pair(0, 0));
	fill(dist, dist + num + 1, 1000000000);
	for (;;)
	{
		if (que.empty())break;
		pii z = que.front();
		que.pop();
		dist[z.second] = z.first;
		vector<int>v = tree.calc(tx[z.second], ty[z.second]);
		for (int i = 0; i < v.size(); i++)
		{
			//printf("::%d %d\n", z.second, v[i]);
			que.push(make_pair(z.first + 1, v[i]));
			frm[v[i]] = z.second;
		}
	}
	if (dist[num] == 1000000000)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", dist[num]);
	vector<int>ans;
	int now = num;
	for (;;)
	{
		ans.push_back(now);
		now = frm[now];
		if (now == 0)break;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}