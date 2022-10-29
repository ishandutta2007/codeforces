#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
using namespace std;
#define SIZE 1000
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
string da[1000], db[1000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)cin >> da[i] >> db[i];
	sat.init(num);
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (da[i][0] != da[j][0] || da[i][1] != da[j][1])continue;
			if (da[i][2] == da[j][2])sat.adde(i, false, j, false), sat.adde(i, false, j, true), sat.adde(i, true, j, false);
			if (da[i][2] == db[j][0])sat.adde(i, false, j, true);
			if (db[i][0] == da[j][2])sat.adde(i, true, j, false);
			if (db[i][0] == db[j][0])sat.adde(i, true, j, true);
		}
	}
	sat.scc();
	if (!sat.issatisfiable())printf("NO\n");
	else
	{
		printf("YES\n");
		vector<bool>v = sat.getval();
		for (int i = 0; i < num; i++)
		{
			printf("%c%c", da[i][0], da[i][1]);
			if (v[i])printf("%c\n", da[i][2]);
			else printf("%c\n", db[i][0]);
		}
	}
}