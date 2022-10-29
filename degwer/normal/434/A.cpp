#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
vector<ll>dat[200000];
ll ar[200000];
int main()
{
	int num, len;
	scanf("%d%d", &num, &len);
	for (int i = 0; i < len; i++)scanf("%I64d", &ar[i]), ar[i]--;
	ll ans = 0;
	for (int i = 0; i < len - 1; i++)if (ar[i] != ar[i + 1])dat[ar[i]].push_back(ar[i + 1]), dat[ar[i + 1]].push_back(ar[i]), ans += abs(ar[i] - ar[i + 1]);
	for (int i = 0; i < num; i++)sort(dat[i].begin(), dat[i].end());
	ll maxi = 0;
	for (int i = 0; i < num; i++)
	{
		if (dat[i].empty())continue;
		ll med = dat[i][dat[i].size() / 2];
		ll sum = 0;
		for (int j = 0; j < dat[i].size(); j++)sum += abs(dat[i][j] - i) - abs(dat[i][j] - med);
		maxi = max(maxi, sum);
	}
	printf("%I64d\n", ans - maxi);
}