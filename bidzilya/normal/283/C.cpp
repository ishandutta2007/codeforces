#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int module=1e9+7;

int n,m,t;
vector<int> next,w,cnt,us,vh;

void change(int v)
{
	int sum=0;
	while (1)
	{
		w[v]+=sum;
		if (!next[v])
			break;
		t-=w[v];
		if (t<0)
		{
			cout << 0 << endl;
			exit(0);
		}
		sum=w[v];
		v=next[v];
	}
}

bool dfs(int v)
{
	us[v]=1;
	if (next[v]>0)
	{
		if (us[next[v]]==1)
		{
			cout << 0 << endl;
			exit(0);
		}
		if (!us[next[v]])
			dfs(next[v]);
	}
	us[v]=2;
}

void checkCyrcle()
{
	us.resize(n+1);
	for (int i=1; i<=n; i++)
		if (!us[i])
			dfs(i);
}

int main()
{
	cin >> n >> m >> t;
	next.assign(n+1,0);
	w.resize(n+1);
	vh.resize(n+1);
	for (int i=1; i<=n; i++)
		cin >> w[i];
	for (int i=0; i<m; i++)
	{
		int a,b;
		cin >> a >> b;
		next[a]=b;
		vh[b]=1;
	}
	checkCyrcle();
	for (int i=1; i<=n; i++)
		if (!vh[i])
			change(i);
	cnt.resize(t+1);
	cnt[0]=1;
	for (int i=1; i<=n; i++)
		for (int j=w[i]; j<=t; j++)
			cnt[j]=(cnt[j]+cnt[j-w[i]])%module;
	cout << cnt[t] << endl;
	return 0;
}