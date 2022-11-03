#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

class SegmentTree
{
	int sz;
	vector<int> t;

	void _add(int v,int tl,int tr,int l,int r,int d)
	{
		if (tl==l && tr==r)
			t[v] += d;
		else
		{
			int m = (tl+tr)/2;
			if (r<=m)_add(2*v,tl,m,l,r,d);
			else
			if (l>m)_add(2*v+1,m+1,tr,l,r,d);
			else
			{
				_add(2*v,tl,m,l,m,d);
				_add(2*v+1,m+1,tr,m+1,r,d);
			}
		}
	}
	int _find(int v,int l,int r,int x)
	{
		if (l==r)
			return t[v];
		else
		{
			int m=(l+r)/2;
			if (x<=m)return t[v]+_find(2*v,l,m,x);
				else return t[v]+_find(2*v+1,m+1,r,x);
		}
	}
public:
	SegmentTree(int _sz):sz(_sz)
	{
		t.resize(4*sz,0);
	}
	void add(int l,int r,int d)
	{
		if (l>r)return;
		_add(1,0,sz-1,max(0,l),min(sz-1,r),d);
	}
	int find(int x)
	{
		return _find(1,0,sz-1,x);
	}
};

const int N = 111111;

int n,q,cnt;
vector<vector<int> > g;
vector<int> num, start, finish, branch;
vector<SegmentTree*> t;

int nv=0;
void dfs(int sv,int pr)
{
	num[sv]=nv++;
	if (pr==0)start[cnt]=num[sv];
	bool isList=true;
	for (int i=0; i<g[sv].size(); i++)
	{
		int u=g[sv][i];
		if (u!=pr)
		{
			dfs(u,sv);
			isList=false;
		}
	}
	if (isList)
		finish[cnt++]=num[sv];
}

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin >> n >> q;
	g.resize(n);
	num.resize(n);
	start.resize(n);
	finish.resize(n);
	branch.resize(n);
	cnt=1;
	for (int i=0; i<n-1; i++)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0,-1);
	for (int i=1; i<cnt; i++)
		for (int j=start[i]; j<=finish[i]; j++)
			branch[j]=i;
	t.resize(cnt);
	t[0] = new SegmentTree(n);
	for (int i=1; i<cnt; i++)
		t[i] = new SegmentTree(finish[i]-start[i]+1);
	for (; q; q--)
	{
		int op;
		cin >> op;
		if (op==0)
		{
			int v,x,d,br;
			cin >> v >> x >> d;
			v = num[v-1];
			if (v==0)
				t[0]->add(0,d,x);
			else
			{
				br = branch[v];
				t[br]->add(v-d-start[br],v+d-start[br],x);
				if (v-d-start[br]<0)
				{
					t[0]->add(0,start[br]+d-v-1,x);
					t[br]->add(0,start[br]+d-v-2,-x);
				}
			}
		}else
		{
			int v;
			cin >> v;
			v = num[v-1];
			if (v==0)
				cout << t[0]->find(0) << endl;
			else
			{
				int br=branch[v];
				cout << t[0]->find(v-start[br]+1) + t[br]->find(v-start[br]) << endl;
			}
		}
	}
	return 0;
}