#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	set<pair<int, int> > det;
	vector<vector<int> > rm(n, vector<int>(0));
	vector<vector<int> > sw(m, vector<int>(0));
	vector<int> detsw(m, 0);
	for(int i = 0; i < n; i++)
	{
	 	int k;
	 	scanf("%d", &k);
	 	rm[i].push_back(k);
	}
	for(int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		for(int z = 0; z < k; z++)
		{
			int j;
			scanf("%d", &j);
			--j;
			rm[j].push_back(i);
			sw[i].push_back(j);
	 	}
	}
	for(int i = 0; i < m; i++)
	{
		if (detsw[i] == 0)
		{
			//cerr << i << " " << 1 << endl;
		 	detsw[i] = 1;
		 	for(auto to : sw[i])
		 	{
		 	 	rm[to][0] ^= 1;
		 	 	for(int z = 1; z <= 2; z++)
		 	 	{
		 	 	 	if (detsw[rm[to][z]] == 0)
		 	 	 	{
		 	 	 	 	det.insert(make_pair(rm[to][z], rm[to][0] ^ 1));
		 	 	 	}
		 	 	}
		 	}
	 	}
	 	while(!det.empty())
	 	{
	 	 	int k = det.begin()->first;
	 	 	int j = det.begin()->second;
	 	 	if (detsw[k] == 1)
	 	 	{
	 	 	 	det.erase(det.begin());
	 	 	 	continue;
	 	 	}
		 	det.erase(det.begin());
	 	 	//cerr << k << " " << j << endl;
	 	 	detsw[k] = 1;
	 	 	for(auto to : sw[k])
		 	{
		 	 	rm[to][0] ^= j;
		 	 	for(int z = 1; z <= 2; z++)
		 	 	{
		 	 	 	if (detsw[rm[to][z]] == 0)
		 	 	 	{
		 	 	 	 	det.insert(make_pair(rm[to][z], rm[to][0] ^ 1));
		 	 	 	}
		 	 	}
		 	}
	 	}
	}
	for(int i = 0; i < n; i++) if (rm[i][0] == 0) 
	{
	 	puts("NO");
	 	return 0;
	}
	puts("YES");
	return 0;
}