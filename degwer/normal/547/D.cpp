#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define INF 2100000000
class splaytreenode
{
public:
	int lko, rko, par, rev;//q, Eq, e|C^ (-1), ]tO(1]) 
	splaytreenode() {}
	splaytreenode(int lko, int rko, int par, int rev) :lko(lko), rko(rko), par(par), rev(rev) {}// m[hl
};
class LCtree//pathq, Ee
{
public:
	vector<splaytreenode>sp;
	void makenode()//1_ m[hl
	{
		sp.push_back(splaytreenode(-1, -1, -1, 0));//m[hl
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
		}
	}
	int getpar(int itr)
	{
		expose(itr);
		if (sp[itr].rev)
		{
			sp[itr].rev = 0;
			if (sp[itr].lko != -1)sp[sp[itr].lko].rev ^= 1, changeko(sp[itr].lko);
			if (sp[itr].rko != -1)sp[sp[itr].rko].rev ^= 1, changeko(sp[itr].rko);
		}
		if(sp[itr].rko!=-1)
		{
			itr=sp[itr].rko;
			for(;;)
			{
				if (sp[itr].rev)
				{
					sp[itr].rev = 0;
					if (sp[itr].lko != -1)sp[sp[itr].lko].rev ^= 1, changeko(sp[itr].lko);
					if (sp[itr].rko != -1)sp[sp[itr].rko].rev ^= 1, changeko(sp[itr].rko);
				}
				if(sp[itr].lko==-1)break;
				itr=sp[itr].lko;
			}
			splay(itr);
			return itr;
		}
		return sp[itr].par;
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
	}
	void evert(int itr)//itr
	{
		expose(itr);
		if (sp[itr].rko == -1)return;
		sp[sp[itr].rko].rev ^= 1;
		changeko(sp[itr].rko);
		sp[itr].rko = -1;
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
typedef pair<int,int>pii;
LCtree tree;
vector<pii>pat;
int ans[200000];
set<pii>se;
map<pii,int>ma;
bool flag[400000];
vector<int>np[400000];



#define SIZE 400000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for(int i=0;i<SIZE;i++)
		{
			par[i]=i;
			ran[i]=0;
			ren[i]=1;
		}
	}
	int find(int a)
	{
		if(a==par[a])return a;
		else return par[a]=find(par[a]);
	}
	void unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a==b)return;
		if(ran[a]>ran[b])
		{
			par[b]=a;
			ren[a]+=ren[b];
		}
		else
		{
			par[a]=b;
			ren[b]+=ren[a];
		}
		if(ran[a]==ran[b])ran[b]++;
	}
};
unionfind uf;


void dfs(int node,int c)
{
	//printf("  %d %d\n",node,c);
	if(flag[node])return;
	flag[node]=true;
	vector<int>ko;
	for(int i=0;i<np[node].size();i++)
	{
		if(!flag[np[node][i]])ko.push_back(np[node][i]);
	}
	for(int i=0;i<ko.size()/2;i++)
	{
		ans[ma[make_pair(node,ko[i])]]=c;
		dfs(ko[i],c);
	}
	for(int i=ko.size()/2;i<ko.size();i++)
	{
		ans[ma[make_pair(node,ko[i])]]=-c;
		dfs(ko[i],-c);
	}
	//printf("    %d %d\n",node,c);
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		za=za*2;
		zb=zb*2+1;
		pat.push_back(make_pair(za,zb));
		ma[make_pair(za,zb)]=i;
		ma[make_pair(zb,za)]=i;
		se.insert(make_pair(za,zb));
		se.insert(make_pair(zb,za));
	}
	for(int i=0;i<400000;i++)tree.makenode();
	for(int i=0;i<pat.size();i++)
	{
		/*for(int j=0;j<6;j++)
		{
			printf("%d  %d %d %d\n",j,tree.sp[j].par,tree.sp[j].lko,tree.sp[j].rko);
		}
		printf("::%d   %d %d\n",i,pat[i].first,pat[i].second);*/
		int x=pat[i].first,y=pat[i].second;
		if(tree.lca(x,y)==-1)
		{
			tree.evert(x);
			tree.evert(y);
			tree.link(x,y);
		}
		else
		{
			//printf("deleted %d\n",i);
			ans[ma[make_pair(x,y)]]=1;
		//	if(pat[ma[make_pair(x,y)]]!=make_pair(x,y)&&pat[ma[make_pair(x,y)]]!=make_pair(y,x))abort();
			se.erase(make_pair(x,y));
			se.erase(make_pair(y,x));
			tree.evert(x);
			int now=y,c=-1;
			for(;;)
			{
				//printf("delete: %d\n",now);
				if(now==x)break;
				int bef=now;
				now=tree.getpar(now);
				tree.cut(bef);
				ans[ma[make_pair(bef,now)]]=c;
				if(pat[ma[make_pair(bef,now)]]!=make_pair(bef,now)&&pat[ma[make_pair(bef,now)]]!=make_pair(now,bef))abort();
				se.erase(make_pair(bef,now));
				se.erase(make_pair(now,bef));
				c*=-1;
			}
		}
	}
	uf.init();
	for(int i=0;i<pat.size();i++)
	{
		if(se.find(pat[i])!=se.end())
		{
			np[pat[i].first].push_back(pat[i].second);
			np[pat[i].second].push_back(pat[i].first);
			//printf("%d %d\n",pat[i].first,pat[i].second);
			if(uf.find(pat[i].first)==uf.find(pat[i].second))abort();
			uf.unite(pat[i].first,pat[i].second);
		}
	}
	fill(flag,flag+num,false);
	for(int i=0;i<400000;i++)if(!flag[i])dfs(i,1);
	for(int i=0;i<num;i++)
	{
		if(ans[i]==1)printf("b");
		if(ans[i]==-1)printf("r");
		//if(ans[i]==0)abort();
	}
	printf("\n");
}