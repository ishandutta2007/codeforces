//  228

#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int low(int x){ return x&-x; }
const int mod = 51123987;
const int maxn = 1e5 + 10;
int n, a[maxn], sum, now, ans;
 
int main()
{
	while (~scanf("%d",&n))
	{
		ans = sum = now = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		for (int i = 1; i < n;i++)
		{
			now += a[i];
			if (now + now == sum) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}