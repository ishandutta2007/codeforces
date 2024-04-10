#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n, m, q;
int a, b;
const int nax = 200005;
int per[nax], gdzie[nax];
int lca[nax][18];
int last[nax], need[nax], t[nax], res[nax];
int daj(int x)
{
	int N = n - 1;
	for(int i = 0; 17 >= i; ++i)
		if((1 << i) & N)
			x = lca[x][i];
	return x;
}
int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; n >= i; ++i)
	{
		scanf("%d", &per[i]);
		gdzie[per[i]] = i;
	}
	for(int i = 1; n >= i; ++i)
	{
		if(gdzie[per[i]] == 1)
			need[per[i]] = per[n];
		else
			need[per[i]] = per[i - 1];
	}
	for(int i = 1; m >= i; ++i)
	{
		scanf("%d", &t[i]);
		lca[i][0] = last[need[t[i]]];
		last[t[i]] = i;
	}
	for(int j = 1; 17 >= j; ++j)
		for(int i = 1; m >= i; ++i)
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
	for(int i = 1; m >= i; ++i)
		res[i] = daj(i);
	for(int i = 1; m >= i; ++i)
		res[i] = max(res[i], res[i - 1]);
		
	for(int i = 1; q >= i; ++i)
	{
		cin >> a >> b;
		cout << (res[b] >= a ? "1" : "0");
	}
	
	return 0;
}