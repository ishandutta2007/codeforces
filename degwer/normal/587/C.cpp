#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class splaytreenode
{
public:
	int lko, rko, par, rev;//q, Eq, e|C^ (-1), ]tO(1]) 
	int seg[10], val[10];
	splaytreenode() {}
	splaytreenode(int lko, int rko, int par, int rev) :lko(lko), rko(rko), par(par), rev(rev) {}// m[hl
};
class LCtree//pathq, Ee
{
public:
	vector<splaytreenode>sp;
	void makenode(vector<int>v)//1_ m[hl
	{
		sp.push_back(splaytreenode(-1, -1, -1, 0));//m[hl
		for (int i = 0; i < 10; i++)sp[sp.size() - 1].seg[i] = sp[sp.size() - 1].val[i] = v[i];
	}
	splaytreenode mergearr(splaytreenode a, splaytreenode b)//m[hl}[W l
	{
		splaytreenode ret;
		int ppp = 0;
		int pptt = 0;
		for (int i = 0; i < 10; i++)
		{
			for (;;)
			{
				if (pptt == 10)break;
				if (b.seg[ppp] < a.seg[i])ret.seg[pptt++] = (b.seg[ppp++]);
				else break;
			}
			if (pptt != 10)ret.seg[pptt++] = (a.seg[i]);
		}
		return ret;
	}
	void update(int itr)//` m[hlXV
	{
		splaytreenode p = sp[itr];
		for (int i = 0; i < 10; i++)p.seg[i] = p.val[i];
		if (sp[itr].lko != -1)
		{
			splaytreenode l = sp[sp[itr].lko];
			p = mergearr(l, p);
		}
		if (sp[itr].rko != -1)
		{
			splaytreenode r = sp[sp[itr].rko];
			p = mergearr(p, r);
		}
		for (int i = 0; i < 10; i++)sp[itr].seg[i] = p.seg[i];
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
		vector<int>pat;
		int now = itr;
		for (;;)
		{
			pat.push_back(now);
			if (ptype(now) == 0)break;
			now = sp[now].par;
		}
		for (int i = pat.size() - 1; i >= 0; i--)
		{
			if (sp[pat[i]].rev)
			{
				sp[pat[i]].rev = 0;
				if (sp[pat[i]].lko != -1)sp[sp[pat[i]].lko].rev ^= 1, changeko(sp[pat[i]].lko);
				if (sp[pat[i]].rko != -1)sp[sp[pat[i]].rko].rev ^= 1, changeko(sp[pat[i]].rko);
			}
		}
		for (int i = 0; i < pat.size(); i++)update(pat[i]);
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
		expose(itr2);
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
	vector<int>getval(int itr)//itrpath()vZ
	{
		expose(itr);
		sp[itr].lko = -1;
		update(itr);
		vector<int>r;
		r.resize(10);
		for (int i = 0; i < 10; i++)r[i] = sp[itr].seg[i];
		return r;
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
vector<int>dat[100000];
int main()
{
	int num, da, query;
	scanf("%d%d%d", &num, &da, &query);
	vector<pii>pat;
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		pat.push_back(make_pair(za - 1, zb - 1));
	}
	for (int i = 0; i < da; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		if (dat[z].size() < 10)dat[z].push_back(i);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = dat[i].size(); j < 10; j++)dat[i].push_back(1000000000);
		tree.makenode(dat[i]);
	}
	for (int i = 0; i < num - 1; i++)
	{
		tree.evert(pat[i].first);
		tree.link(pat[i].first, pat[i].second);
	}
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--;
		zb--;
		tree.evert(za);
		vector<int>v = tree.getval(zb);
		vector<int>ans;
		for (int i = 0; i < min(zc, int(v.size())); i++)
		{
			if (v[i] != 1000000000)ans.push_back(v[i]);
		}
		printf("%d", ans.size());
		for (int i = 0; i < ans.size(); i++)printf(" %d", ans[i] + 1); printf("\n");
	}
}