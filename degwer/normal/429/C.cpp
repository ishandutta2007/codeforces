#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
bool isok = false;
set<vector<int> >se;
set<vector<int> >s2;
vector<vector<int> >nx;
void get(vector<int>v, vector<int>n, int mok)
{
	n.push_back(mok);
	if (s2.find(n) != s2.end())return;
	s2.insert(n);
	n.pop_back();
	if (mok < 0)return;
	if (v.empty())
	{
		if (mok == 0)
		{
			nx.push_back(n);
		}
		return;
	}
	int x = v[v.size() - 1];
	v.pop_back();
	get(v, n, mok - x);
	n.push_back(x);
	get(v, n, mok);
}
void calc(vector<int>now, vector<int>nd)
{
	//for (int i = 0; i < now.size(); i++)printf("%d ", now[i]); printf("   "); for (int i = 0; i < nd.size(); i++)printf("%d ", nd[i]); printf("\n");
	if (nd.empty())
	{
		if (now.size() == 1)isok = true;
		return;
	}
	if (se.find(now) != se.end())return;
	se.insert(now);
	int x = nd[nd.size() - 1];
	nd.pop_back();
	vector<vector<int> >nxt;
	nx.clear();
	vector<int>ddd;
	s2.clear();
	get(now, ddd, x - 1);
	nxt = nx;
	/*for (int i = 0; i < nxt.size(); i++)
	{
		for (int j = 0; j < nxt[i].size(); j++)printf("%d ", nxt[i][j]); printf(":::\n");
	}*/
	for (int i = 0; i < nxt.size(); i++)
	{
		if (nxt[i].size() == now.size() - 1)continue;
		nxt[i].push_back(x);
		sort(nxt[i].begin(), nxt[i].end());
		calc(nxt[i], nd);
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v1, v2;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (z == 1)v1.push_back(z);
		else v2.push_back(z);
	}
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end());
	calc(v1, v2);
	if (isok)printf("YES\n");
	else printf("NO\n");
}