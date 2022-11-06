#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll; 
int fa[204800], arr[204800], num[204800]; 
bool leaf[204800]; 
vector<int> rt, cyc, leaves; 
int getfa(int x)
{
	if (x == fa[x])
		return x; 
	return fa[x] = getfa(fa[x]); 
}
int main() 
{
	// freopen("B.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		fa[i] = i; 
		leaf[i] = true; 
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		int &x = arr[i]; 
		x--; 
		if (i == x)
		{
			rt.pb(i); 
			continue; 
		}
		if (getfa(i) == getfa(x))
		{
			num[cyc.size()] = x; 
			cyc.push_back(i); 
			continue; 
		}
		fa[getfa(i)] = getfa(x); 
		leaf[x] = false; 
		// cout << i << endl; 
	}
	for (int i = 0; i < n; i++)
	{
		if (leaf[i])
			leaves.pb(i); 
	}
	int ans = 0; 
	int tot = cyc.size(); 
	while (tot)
	{
		if (getfa(cyc[tot - 1]) != getfa(num[tot - 1]))
		{
			tot--; 
			continue; 
		}
		int idx = 0; 
		while (idx < leaves.size() && getfa(cyc[tot - 1]) == getfa(leaves[idx]))
			idx++; 
		if (idx >= leaves.size())
		{
			arr[cyc[tot - 1]] = cyc[tot - 1]; 
			fa[cyc[tot - 1]] = cyc[tot - 1]; 
			rt.pb(cyc[tot - 1]); 
			ans++; 
			tot--; 
			continue; 
		}
		arr[cyc[tot - 1]] = leaves[idx]; 
		fa[getfa(cyc[tot - 1])] = getfa(leaves[idx]); 
		tot--; 
		ans++; 
	}
	if (!rt.size())
	{
		arr[leaves[0]] = leaves[0]; 
		fa[leaves[0]] = leaves[0]; 
		ans++; 
		rt.pb(leaves[0]); 
	}
	tot = rt.size(); 
	while (tot > 1)
	{
		// cout << rt[tot - 1] << " " << tot << endl; 
		int idx = 0; 
		while (idx < leaves.size() && getfa(rt[tot - 1]) == getfa(leaves[idx]))
			idx++; 
		if (idx >= leaves.size())
		{
			arr[leaves[0]] = rt[tot - 1]; 
			fa[getfa(rt[tot - 1])] = getfa(leaves[0]); 
			ans++; 
			tot--; 
			continue; 
		}
		arr[rt[tot - 1]] = leaves[idx]; 
		fa[getfa(rt[tot - 1])] = getfa(leaves[idx]); 
		tot--; 
		ans++; 
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d%c", arr[i] + 1, " \n"[i + 1 == n]);
	return 0; 
}