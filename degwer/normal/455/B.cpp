#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
class trie
{
public:
	int nxt[200000][26];
	int pt;
	void init()
	{
		pt = 1;
		fill(nxt[0], nxt[0] + 26, -1);
	}
	void add(string s)
	{
		int now = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (nxt[now][s[i] - 'a'] == -1)
			{
				fill(nxt[pt], nxt[pt] + 26, -1);
				nxt[now][s[i] - 'a'] = pt++;
			}
			now = nxt[now][s[i] - 'a'];
		}
	}
	bool dfs1(int node)
	{
		bool x = false;
		for (int i = 0; i < 26; i++)
		{
			if (nxt[node][i] != -1)x |= (!(dfs1(nxt[node][i])));
		}
		return x;
	}
	bool dfs2(int node)
	{
		int cnt = 0;
		bool x = false;
		for (int i = 0; i < 26; i++)
		{
			if (nxt[node][i] != -1)x |= (!(dfs2(nxt[node][i]))), cnt++;
		}
		if (cnt == 0)return true;
		return x;
	}
};
trie tr;
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	tr.init();
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		tr.add(s);
	}
	bool f1 = tr.dfs1(0), f2 = tr.dfs2(0);
	if (!f1)printf("Second\n");
	else if (f2)printf("First\n");
	else if (kai % 2 == 0)printf("Second\n");
	else printf("First\n");
}