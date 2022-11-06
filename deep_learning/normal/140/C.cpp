#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdio>
#include <queue>
#include <map>
#define mp make_pair
using namespace std; 
int arr[100005], cnt; 
map<int, int> app; 
pair<pair<int, int>, int> ans[100005]; 
int main()
{
	// freopen("140C.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		app[arr[i]]++; 
	}
	priority_queue<pair<int, int> > que; 
	for (map<int, int>::iterator it = app.begin(); it != app.end(); it++)
		que.push(mp(it->second, it->first)); 
	while (que.size() >= 3)
	{
		pair<int, int> x = que.top(); 
		que.pop(); 
		pair<int, int> y = que.top(); 
		que.pop(); 
		pair<int, int> z = que.top(); 
		que.pop(); 
		ans[cnt++] = mp(mp(x.second, y.second), z.second); 
		if (x.first > 1)
			que.push(mp(x.first - 1, x.second)); 
		if (y.first > 1)
			que.push(mp(y.first - 1, y.second)); 
		if (z.first > 1)
			que.push(mp(z.first - 1, z.second)); 
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
	{
		int tmp[] = {ans[i].first.first, ans[i].first.second, ans[i].second}; 
		sort(tmp, tmp + 3); 
		printf("%d %d %d\n", tmp[2], tmp[1], tmp[0]);
	}
	return 0; 
}