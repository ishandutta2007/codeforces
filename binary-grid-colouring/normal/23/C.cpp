#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456*2];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n * 2 - 1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			pii[i] = make_pair(make_pair(x, y), i);
		}
		sort(pii+1, pii + n * 2 - 1+1);
		printf("YES\n");
		for (int i = 1; i <= n-1; i++)
		{
			if (pii[i * 2 - 1].first.second > pii[i * 2].first.second)
				printf("%d ", pii[i * 2 - 1].second);
			else
				printf("%d ", pii[i * 2].second);
		}		
		printf("%d\n", pii[2 * n - 1].second);
	}
	return 0;
}