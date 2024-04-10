#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 131072
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
typedef pair<pii, pii>pi4;
typedef pair<pi4, int>pi5;
bool ans[200000][2];
void calc(vector<pii>vec, vector<pi3>que, int len, int tt)
{
//	for (int i = 0; i < vec.size(); i++)printf("%d %d   ", vec[i].first, vec[i].second); printf("\n");
//	for (int i = 0; i < que.size(); i++)printf("%d %d %d   ", que[i].first.first, que[i].first.second, que[i].second); printf("\n");
//	printf("%d\n\n", len);
	vector<pi3>zq;
	for (int i = 0; i < que.size(); i++)if (ans[que[i].second][tt])zq.push_back(que[i]);
	que = zq;
	vector<pi3>q;
	q.resize(vec.size() + que.size());
	int pp = 0;
	int qp = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		for (;;)
		{
			if (pp == que.size())break;
			if (que[pp].first.first <= vec[i].second)
			{
				q[qp++] = (make_pair(make_pair(que[pp].first.first, que[pp].first.second), que[pp].second));
				pp++;
			}
			else break;
		}
		q[qp++] = (make_pair(make_pair(vec[i].second, vec[i].first), -1));
	}
	for (int i = pp; i < que.size();i++)q[qp++] = (make_pair(make_pair(que[i].first.first, que[i].first.second), que[i].second));
	vector<vector<int> >dat;
	dat.resize(len);
	for (int i = 0; i < vec.size(); i++)
	{
		dat[vec[i].first].push_back(vec[i].second);
	}
	for (int i = 0; i < len; i++)
	{
		dat[i].push_back(SIZE);
	}
	vector<int>pt;
	for (int i = 0; i < len; i++)pt.push_back(0);
	int now = 0;
	for (int i = 0; i < len; i++)now = max(now, dat[i][0]);
	for (int i = 0; i < q.size(); i++)
	{
		if (q[i].second >= 0)
		{
			if (now > q[i].first.second)ans[q[i].second][tt] = false;
		}
		else
		{
			pt[q[i].first.second]++;
			now = max(now, dat[q[i].first.second][pt[q[i].first.second]]);
		}
	}
}
class segtree
{
public:
	vector<pii>vec[SIZE * 2];
	vector<pi3>que[SIZE * 2];
	void addr(int x, int y)
	{
		int t = x;
		t += SIZE;
		for (;;)
		{
			if (t == 0)break;
			vec[t].push_back(make_pair(x, y));
			t /= 2;
		}
	}
	void addq(int beg, int end, int node, int lb, int ub, int ly, int uy, int t)
	{
		if (ub < beg || end < lb)return;
		if (beg <= lb&&ub <= end)
		{
			que[node].push_back(make_pair(make_pair(ly, uy), t));
			return;
		}
		addq(beg, end, node * 2, lb, (lb + ub) / 2, ly, uy, t);
		addq(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, ly, uy, t);
	}
	void dfs(int node, int lb, int ub, int tt)
	{
		for (int i = 0; i < vec[node].size(); i++)vec[node][i].first -= lb;
	//	printf("node %d\n", node);
		if(!que[node].empty())calc(vec[node], que[node], ub - lb + 1, tt);
		if (lb == ub)return;
		dfs(node * 2, lb, (lb + ub) / 2, tt);
		dfs(node * 2 + 1, (lb + ub) / 2 + 1, ub, tt);
	}
};
segtree tx, ty;
int main()
{
	int mx, my, num, query;
	scanf("%d%d%d%d", &mx, &my, &num, &query);
	vector<pii>vx, vy;
	vector<pi5>qx, qy;
	vx.resize(num);
	vy.resize(num);
	qx.resize(query);
	qy.resize(query);
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		vx[i] = (make_pair(zb, za));
		vy[i] = (make_pair(za, zb));
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	for (int i = 0; i < num;i++)
	{
		tx.addr(vx[i].second, vx[i].first);
		ty.addr(vy[i].second, vy[i].first);
	}
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		qx[i] = (make_pair(make_pair(make_pair(zb, zd), make_pair(za, zc)), i));
		qy[i] = (make_pair(make_pair(make_pair(za, zc), make_pair(zb, zd)), i));
	}
	sort(qx.begin(), qx.end());
	sort(qy.begin(), qy.end());
	for (int i = 0; i < query; i++)
	{
		tx.addq(qx[i].first.second.first, qx[i].first.second.second, 1, 0, SIZE - 1, qx[i].first.first.first, qx[i].first.first.second, qx[i].second);
	}
	for (int i = 0; i < query; i++)ans[i][0] = ans[i][1] = true;
	tx.dfs(1, 0, SIZE - 1, 0);
	for (int i = 0; i < query;i++)
	{
		if(!ans[qy[i].second][0])ty.addq(qy[i].first.second.first, qy[i].first.second.second, 1, 0, SIZE - 1, qy[i].first.first.first, qy[i].first.first.second, qy[i].second);
	}
	ty.dfs(1, 0, SIZE - 1, 1);
	for (int i = 0; i < query; i++)
	{
		if (ans[i][0]||ans[i][1])printf("YES\n");
		else printf("NO\n");
	}
}