#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>
#include <cstdio>
#define mp make_pair
using namespace std; 
typedef long long ll; 
pair<int, int> arr[1024]; 
int w[1024], h[1024]; 
int main()
{
	// freopen("529B.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d%d", w + i, h + i); 
	ll ans = 1e18; 
	int w2[1024], h2[1024]; 
	memcpy(w2, w, sizeof(w));
	memcpy(h2, h, sizeof(h)); 
	for (int i = 0; i <= 1000; i++)
	{
		bool f = true; 
		for (int j = 0; j < n; j++)
		{
			if (h[j] > i && w[j] > i)
			{
				f = false; 
				break; 
			}
		}
		if (!f)
			continue;
		int tot = n / 2; 
		for (int j = 0; j < n; j++)
		{
			if (h[j] > i)
			{
				swap(h[j], w[j]); 
				tot--; 
			}
		}
		if (tot < 0)
		{
			memcpy(w, w2, sizeof(w)); 
			memcpy(h, h2, sizeof(h)); 
			continue; 
		}
		int cur = 0; 
		for (int j = 0; j < n; j++)
		{
			if (h[j] <= i && w[j] <= i)
				arr[cur++] = mp(w[j] - h[j], j); 
		}
		sort(arr, arr + cur, greater<pair<int, int> >());
		for (int j = 0; j < cur; j++)
		{
			if (arr[j].first < 0 || tot <= 0)
				break;
			swap(w[arr[j].second], h[arr[j].second]); 
			tot--; 
		}
		int sum = 0; 
		for (int j = 0; j < n; j++)
			sum += w[j]; 
		// cout << i << " " << sum << endl; 
		ans = min(ans, (ll)sum * i); 
		memcpy(w, w2, sizeof(w)); 
		memcpy(h, h2, sizeof(h)); 
	}
	cout << ans << endl; 
	return 0; 
}