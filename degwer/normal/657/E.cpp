#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 300000//_
#define ROOT 0
vector<int>pat[SIZE];
vector<int>rev[SIZE];
vector<int>etype[SIZE];//1: 2:t -1: -2:t [v
int ord[SIZE];
int low[SIZE];
int ordpt = 0;
bool flag[SIZE];
void adde(int s, int t)//s-t
{
	pat[s].push_back(t);
	pat[t].push_back(s);
	rev[s].push_back(pat[t].size() - 1);
	rev[t].push_back(pat[s].size() - 1);
	etype[s].push_back(0);
	etype[t].push_back(0);
}
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	ord[node] = ordpt++;
	for (int i = 0; i<pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			etype[node][i] = 1;
			etype[pat[node][i]][rev[node][i]] = 2;
			dfs(pat[node][i]);
		}
		else
		{
			if (etype[node][i] == 0)
			{
				etype[node][i] = -1;
				etype[pat[node][i]][rev[node][i]] = -2;
			}
		}
	}
}
void calclow(int node)
{
	low[node] = ord[node];
	for (int i = 0; i<pat[node].size(); i++)
	{
		if (etype[node][i] == 1)
		{
			calclow(pat[node][i]);
			low[node] = min(low[node], low[pat[node][i]]);
		}
		if (etype[node][i] == -1)
		{
			low[node] = min(low[node], ord[pat[node][i]]);
		}
	}
}
bool isbridge(int node, int k)//node-pat[node][k]
{
	if (etype[node][k] <= 0)return false;
	if (etype[node][k] == 2)
	{
		int t = pat[node][k];
		k = rev[node][k];
		node = t;
	}
	if (low[pat[node][k]]>ord[node])return true;
	else return false;
}
bool isartic(int node)//node_
{
	if (node == ROOT)
	{
		int cnt = 0;
		for (int i = 0; i<pat[node].size(); i++)if (etype[node][i] == 1)cnt++;
		if (cnt >= 2)return true;
		else return false;
	}
	else
	{
		for (int i = 0; i<pat[node].size(); i++)
		{
			if (etype[node][i] == 1)
			{
				if (low[pat[node][i]] >= ord[node])return true;
			}
		}
		return false;
	}
}
int tpt = 0;
int tot[SIZE];//Otm[h->Vm[h
vector<int>ko[SIZE];//V
void maketree(int node, int d)
{
	tot[node] = d;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (etype[node][i] == 1)
		{
			if (isbridge(node, i))
			{
				tpt++;
				ko[d].push_back(tpt);
				maketree(pat[node][i], tpt);
			}
			else maketree(pat[node][i], d);
		}
	}
}
int ppp[1000000];
class splaytreenode
{
public:
	int lko, rko, par, rev;//q, Eq, e|C^ (-1), ]tO(1]) 
	int val, mini, flag;
	splaytreenode() {}
	splaytreenode(int lko, int rko, int par, int rev, int val, int mini, int flag) :lko(lko), rko(rko), par(par), rev(rev), val(val), mini(mini), flag(flag) {}// m[hl
};
class LCtree//pathq, Ee
{
public:
	vector<splaytreenode>sp;
	void makenode(int n)//1_ m[hl
	{
		sp.push_back(splaytreenode(-1, -1, -1, 0, n, n, 0));//m[hl
	}
	splaytreenode mergearr(splaytreenode a, splaytreenode b)//m[hl}[W l
	{
		splaytreenode ret;
		ret.mini = min(a.mini, b.mini);
		return ret;
	}
	void update(int itr)//` m[hlXV
	{
		int m = sp[itr].val;
		if (sp[itr].lko != -1)
		{
			m = min(m, sp[sp[itr].lko].mini);
		}
		if (sp[itr].rko != -1)
		{
			m = min(m, sp[sp[itr].rko].mini);
		}
		sp[itr].mini = m;
	}
	void updateseg(int itr, int n)//l tO tOl
	{
		sp[itr].val += n;
		sp[itr].mini += n;
	}
	int ptype(int itr)//splayeq-1, 0, Eq1
	{
		if (sp[itr].par == -1)return 0;
		if (sp[sp[itr].par].lko == itr)return -1;
		if (sp[sp[itr].par].rko == itr)return 1;
		return 0;
	}
	void rotl(int itr)//oO
	{
		int p = sp[itr].par;
		if (ptype(p) == 0)
		{
			sp[itr].par = sp[p].par;
		}
		else if (ptype(p) == -1)
		{
			sp[itr].par = sp[p].par;
			sp[sp[p].par].lko = itr;
		}
		else
		{
			sp[itr].par = sp[p].par;
			sp[sp[p].par].rko = itr;
		}
		sp[p].par = itr;
		sp[p].rko = sp[itr].lko;
		if (sp[itr].lko != -1)sp[sp[itr].lko].par = p;
		sp[itr].lko = p;
		update(p);
		update(itr);
	}
	void rotr(int itr)//oO
	{
		int p = sp[itr].par;
		if (ptype(p) == 0)
		{
			sp[itr].par = sp[p].par;
		}
		else if (ptype(p) == -1)
		{
			sp[itr].par = sp[p].par;
			sp[sp[p].par].lko = itr;
		}
		else
		{
			sp[itr].par = sp[p].par;
			sp[sp[p].par].rko = itr;
		}
		sp[p].par = itr;
		sp[p].lko = sp[itr].rko;
		if (sp[itr].rko != -1)sp[sp[itr].rko].par = p;
		sp[itr].rko = p;
		update(p);
		update(itr);
	}
	void changeko(int itr)//Eq] lL
	{
		swap(sp[itr].lko, sp[itr].rko);
	}
	void splay(int itr)//sv
	{
		int pt = 0;
		int now = itr;
		for (;;)
		{
			ppp[pt++] = now;
			if (ptype(now) == 0)break;
			now = sp[now].par;
		}
		for (int i = pt - 1; i >= 0; i--)
		{
			if (sp[ppp[i]].rev)
			{
				sp[ppp[i]].rev = 0;
				if (sp[ppp[i]].lko != -1)sp[sp[ppp[i]].lko].rev ^= 1, changeko(sp[ppp[i]].lko);
				if (sp[ppp[i]].rko != -1)sp[sp[ppp[i]].rko].rev ^= 1, changeko(sp[ppp[i]].rko);
			}
			if (sp[ppp[i]].flag != 0)
			{
				if (sp[ppp[i]].lko != -1)updateseg(sp[ppp[i]].lko, sp[ppp[i]].flag), sp[sp[ppp[i]].lko].flag += sp[ppp[i]].flag;
				if (sp[ppp[i]].rko != -1)updateseg(sp[ppp[i]].rko, sp[ppp[i]].flag), sp[sp[ppp[i]].rko].flag += sp[ppp[i]].flag;
				sp[ppp[i]].flag = 0;
			}
		}
		for (int i = 0; i < pt; i++)update(ppp[i]);
		for (;;)
		{
			if (ptype(itr) == 0)break;
			int p1 = ptype(itr), p2 = ptype(sp[itr].par);
			if (p2 == 0)
			{
				if (p1 == -1)rotr(itr);
				else rotl(itr);
			}
			else
			{
				if (p1 == -1 && p2 == -1)rotr(sp[itr].par), rotr(itr);
				if (p1 == -1 && p2 == 1)rotr(itr), rotl(itr);
				if (p1 == 1 && p2 == -1)rotl(itr), rotr(itr);
				if (p1 == 1 && p2 == 1)rotl(sp[itr].par), rotl(itr);
			}
		}
	}
	void expose(int itr)//sv
	{
		for (;;)
		{
			splay(itr);
			if (sp[itr].par == -1)break;
			int p = sp[itr].par;
			splay(p);
			sp[p].lko = itr;
			update(p);
		}
	}
	void link(int itr1, int itr2)//itr1eitr2
	{
		expose(itr1);
		//expose(itr2);
		sp[itr1].par = itr2;
	}
	void cut(int itr)//itref oO
	{
		expose(itr);
		sp[sp[itr].rko].par = -1;
		sp[itr].rko = -1;
		update(itr);
	}
	void evert(int itr)//itr
	{
		expose(itr);
		if (sp[itr].rko == -1)return;
		sp[sp[itr].rko].rev ^= 1;
		changeko(sp[itr].rko);
		sp[itr].rko = -1;
		update(itr);
	}
	void updateval(int itr, int n)//itrpath()_lXV Ppath[evert
	{
		expose(itr);
		sp[itr].lko = -1;
		update(itr);
		updateseg(itr, n);
		sp[itr].flag += n;
	}
	int getval(int itr)//itrpath()vZ
	{
		expose(itr);
		sp[itr].lko = -1;
		update(itr);
		return sp[itr].mini;
	}
	int lca(int itr1, int itr2)//itr1itr2LCA -1
	{
		if (itr1 == itr2)return itr1;
		expose(itr2);
		expose(itr1);
		int v = itr2;
		int bef = itr2;
		for (;;)
		{
			if (sp[itr2].par == -1)break;
			if (ptype(itr2) == 0)
			{
				v = sp[itr2].par;
			}
			bef = itr2;
			itr2 = sp[itr2].par;
		}
		if (itr1 != itr2)return -1;
		if (ptype(bef) != 1)return itr1;
		return v;
	}
};
LCtree tree;
typedef pair<int, int>pii;
int main()
{
	int num, way, query;
	scanf("%d%d%d", &num, &way, &query);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		adde(za, zb);
	}
	fill(flag, flag + num, false);
	for (int i = 0; i < num; i++)
	{
		if (!flag[i])
		{
			dfs(i);
			calclow(i);
			maketree(i, tpt);
			tpt++;
		}
	}
	for (int i = 0; i < tpt; i++)
	{
		tree.makenode(1000000000);
	}
	int hpt = tpt;
	for (int i = 0; i < tpt; i++)
	{
		for (int j = 0; j < ko[i].size(); j++)
		{
			tree.makenode(0);
			tree.sp[ko[i][j]].par = hpt;
			tree.sp[hpt].lko = ko[i][j];
			tree.sp[hpt].mini = 0;
			tree.sp[hpt].par = i;
			hpt++;
		}
	}
	int now = 0;
	for (int p = 0; p < query; p++)
	{
		int nq, nw;
		scanf("%d%d", &nq, &nw);
		vector<int>vec;
		for (int i = 0; i < nq; i++)
		{
			int z;
			scanf("%d", &z);
			z--;
			vec.push_back(tot[(z + now) % num]);
		}
		vector<pii>wy;
		for (int i = 0; i < nw; i++)
		{
			int za, zb;
			scanf("%d%d", &za, &zb);
			za--;
			zb--;
			wy.push_back(make_pair(tot[(za + now) % num], tot[(zb + now) % num]));
		}
		if (nq == 1)
		{
			printf("YES\n");
			now += (p + 1);
			now %= num;
			continue;
		}
		vector<bool>fl;
		for (int i = 0; i < wy.size(); i++)
		{
			if (tree.lca(wy[i].first, wy[i].second) == -1)
			{
				tree.makenode(0);
				tree.link(hpt, wy[i].first);
				tree.evert(hpt);
				tree.link(hpt, wy[i].second);
				fl.push_back(true);
				hpt++;
			}
			else fl.push_back(false);
		}
		for (int i = 0; i < wy.size(); i++)
		{
			if (!fl[i])
			{
				tree.evert(wy[i].first);
				tree.updateval(wy[i].second, 1);
			}
		}
		bool ans = true;
		tree.evert(vec[0]);
		for (int i = 1; i < vec.size(); i++)
		{
			if (tree.lca(vec[0], vec[i]) == -1)ans = false;
			else
			{
				int t = tree.getval(vec[i]);
				if (t == 0)ans = false;
			}
		}
		if (ans)
		{
			printf("YES\n");
			now += (p + 1);
			now %= num;
		}
		else printf("NO\n");
		for (int i = 0; i < wy.size(); i++)
		{
			if (!fl[i])
			{
				tree.evert(wy[i].first);
				tree.updateval(wy[i].second, -1);
			}
		}
		for (int i = 0; i < wy.size(); i++)
		{
			if (fl[i])
			{
				tree.evert(wy[i].first);
				tree.cut(wy[i].second);
			}
		}
	}
}