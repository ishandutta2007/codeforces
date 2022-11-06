#include <algorithm>
#include <cstdio>
#include <vector>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define pp pop_back
std::vector<int> seq, ans(1000, 0), arr[25]; 
void work(int dep)
{
	if (seq.size() > ans.size())
		return; 
	std::sort(arr[dep].begin(), arr[dep].end()); 
	arr[dep].erase(std::unique(arr[dep].begin(), arr[dep].end()), arr[dep].end()); 
	if (dep >= 18)
	{
		if (arr[dep].size() == 1 && !arr[dep][0])
			ans = seq; 
		return; 
	}
	arr[dep + 1] = arr[dep]; 
	bool odd = false; 
	for (int x : arr[dep])
		odd |= my_abs(x) & 1; 
	if (!odd)
	{
		for (int &x : arr[dep + 1])
			x >>= 1; 
		work(dep + 1); 
		return; 
	}
	seq.pb(1 << dep); 
	for (int &x : arr[dep + 1])
	{
		if (my_abs(x) & 1)
			x--; 
		x >>= 1; 
	}
	work(dep + 1); 
	seq.pp(); 
	seq.pb(-(1 << dep)); 
	arr[dep + 1] = arr[dep]; 
	for (int &x : arr[dep + 1])
	{
		if (my_abs(x) & 1)
			x++; 
		x >>= 1; 
	}
	work(dep + 1); 
	seq.pp(); 
}
int main()
{
	// freopen("949E.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		arr[0].pb(x); 
	}
	work(0); 
	printf("%d\n", (int)ans.size());
	for (int x : ans)
		printf("%d ", x);
	return 0; 
}