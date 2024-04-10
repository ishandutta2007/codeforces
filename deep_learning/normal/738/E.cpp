#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std;
vector<int> vec; 
int main()
{
	// freopen("738E.in", "r", stdin); 
	int n, id; 
	scanf("%d%d", &n, &id); 
	id--; 
	int cnt = 0, mx = 0, ans = 0; 
	for (int i = 0; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		if (!x && i != id)
			x = 1e9; 
		else if (i == id && x)
		{
			ans++; 
			x = 0; 
		}
		vec.pb(x); 
	}
	sort(vec.begin(), vec.end()); 
	int cur = 1, tot = vec.size(); 
	for (int i = 1; i < tot; cur++)
	{
		if (cur != vec[i])
		{
			ans++; 
			tot--; 
		}
		else
		{
			while (i < tot && cur == vec[i])
				i++; 
		}
	}
	printf("%d\n", ans);
	return 0; 
}