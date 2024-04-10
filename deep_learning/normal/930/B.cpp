#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
char str[5005]; 
int cnt[5005][35]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("930B.in", "r", stdin); 
#endif
	scanf("%s", str); 
	int n = strlen(str), ans = 0; 
	for (int i = 0; i < 26; i++)
	{
		memset(cnt, 0, sizeof(cnt)); 
		for (int j = 0; j < n; j++)
		{
			if (str[j] != i + 'a')
				continue; 
			for (int k = 0; k < n; k++)
				cnt[(k - j + n) % n][str[k] - 'a']++; 
		}
		int res = 0; 
		for (int j = 0; j < n; j++)
		{
			int sum = 0; 
			for (int k = 0; k < 26; k++)
				sum += cnt[j][k] == 1; 
			res = std::max(res, sum); 
		}
		ans += res; 
	}
	printf("%.10lf\n", (double)ans / n);
	return 0; 
}