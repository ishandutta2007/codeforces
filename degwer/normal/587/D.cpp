#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define SIZE 200000
class twosat
{
public:
	int num;//
	vector<int>pat[SIZE * 2];
	vector<int>rpat[SIZE * 2];
	bool flag[SIZE * 2];
	int bun[SIZE * 2];
	vector<int>topo;
	void print()
	{
		for (int i = 0; i < num * 2; i++)
		{
			for (int j = 0; j < pat[i].size(); j++)
			{
				printf("%d %d\n", i, pat[i][j]);
			}
		}
	}
	void init(int n)
	{
		num = n;
		for (int i = 0; i < SIZE * 2; i++)
		{
			pat[i].clear();
			rpat[i].clear();
		}
	}
	void adde(int ax, bool ay, int bx, bool by)//ay ax or by bx 
	{
		int t = ax * 2, s = bx * 2;
		if ((ay) && (by))
		{
			pat[t + 1].push_back(s);
			pat[s + 1].push_back(t);
			rpat[t].push_back(s + 1);
			rpat[s].push_back(t + 1);
		}
		if ((!ay) && (by))
		{
			pat[t].push_back(s);
			pat[s + 1].push_back(t + 1);
			rpat[t + 1].push_back(s + 1);
			rpat[s].push_back(t);
		}
		if ((ay) && (!by))
		{
			pat[t + 1].push_back(s + 1);
			pat[s].push_back(t);
			rpat[t].push_back(s);
			rpat[s + 1].push_back(t + 1);
		}
		if ((!ay) && (!by))
		{
			pat[t].push_back(s + 1);
			pat[s].push_back(t + 1);
			rpat[t + 1].push_back(s);
			rpat[s + 1].push_back(t);
		}
	}
	void dfs(int node)
	{
		if (flag[node])return;
		flag[node] = true;
		for (int i = 0; i < pat[node].size(); i++)dfs(pat[node][i]);
		topo.push_back(node);
	}
	void rdfs(int node, int b)
	{
		if (flag[node])return;
		flag[node] = true;
		bun[node] = b;
		for (int i = 0; i < rpat[node].size(); i++)rdfs(rpat[node][i], b);
	}
	void scc()
	{
		fill(flag, flag + SIZE * 2, false);
		topo.clear();
		for (int i = 0; i < num * 2; i++)if (!flag[i])dfs(i);
		fill(flag, flag + SIZE * 2, false);
		int pt = 0;
		for (int i = num * 2 - 1; i >= 0; i--)if (!flag[topo[i]])rdfs(topo[i], pt++);
	}
	bool issatisfiable()
	{
		for (int i = 0; i < num; i++)
		{
			if (bun[i * 2] == bun[i * 2 + 1])return false;
		}
		return true;
	}
	vector<bool>getval()
	{
		vector<bool>ret;
		for (int i = 0; i < num; i++)
		{
			if (bun[i * 2] < bun[i * 2 + 1])ret.push_back(false);
			else ret.push_back(true);
		}
		return ret;
	}
};
twosat sat;
int px[50000], py[50000], col[50000], cst[50000];
int pts[50000];
int pt;
typedef pair<int, int>pii;
map<pii, vector<int> >ma;
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < way; i++)
	{
		scanf("%d%d%d%d", &px[i], &py[i], &col[i], &cst[i]);
		px[i]--, py[i]--;
		ma[make_pair(px[i], col[i])].push_back(i);
		ma[make_pair(py[i], col[i])].push_back(i);
	}
	int beg = 0, end = 1050000000;
	for (;;)
	{
		int med = (beg + end) / 2;
		//printf("%d\n", med);
		for (int i = 0; i < num; i++)pts[i] = -1;
		sat.init(way * 3 + 1);
		pt = way;
		for (int i = 0; i < way; i++)
		{
			if (pts[px[i]] == -1)pts[px[i]] = i;
			else
			{
				sat.adde(i, true, pts[px[i]], true);
				sat.adde(pt, false, i, true);
				sat.adde(pt, false, pts[px[i]], true);
				pts[px[i]] = pt++;
			}
			if (pts[py[i]] == -1)pts[py[i]] = i;
			else
			{
				sat.adde(i, true, pts[py[i]], true);
				sat.adde(pt, false, i, true);
				sat.adde(pt, false, pts[py[i]], true);
				pts[py[i]] = pt++;
			}
			if (med < cst[i])
			{
				sat.adde(i, true, way * 3, true);
				sat.adde(i, true, way * 3, false);
			}
		}
		map<pii, vector<int> >::iterator it = ma.begin();
		for (;;)
		{
			if (it == ma.end())break;
			vector<int>v = (*it).second;
			if (v.size() > 2)
			{
				printf("No\n");
				return 0;
			}
			for (int i = 1; i < v.size(); i++)
			{
				sat.adde(v[i - 1], false, v[i], false);
			}
			it++;
		}
		//sat.print();
		sat.scc();
		//for (int i = 0; i < (way * 3 + 1) * 2; i++)printf("%d %d\n", i, sat.bun[i]);
		if (beg == end)break;
		if (sat.issatisfiable())end = med;
		else beg = med + 1;
	}
	if (beg > 1000000000)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	vector<bool>dat = sat.getval();
	vector<int>ret;
	for (int i = 0; i < way; i++)if (!dat[i])ret.push_back(i);
	printf("%d %d\n", beg, ret.size());
	for (int i = 0; i < ret.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ret[i] + 1);
	}
	printf("\n");
}