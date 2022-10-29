#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<stdlib.h>
using namespace std;
int d1[200000], d2[200000];
map<int, int>ma;
typedef long long ll;
int main()
{
	int na, nb, kai;
	scanf("%d%d%d", &na, &nb, &kai);
	for (int i = 0; i < na; i++)scanf("%d", &d1[i]);
	for (int j = 0; j < nb; j++)scanf("%d", &d2[j]);
	if (nb > na / kai + 1)
	{
		printf("0\n");
		return 0;
	}
	vector<int>ans;
	for (int k = 0; k < kai; k++)
	{
		ma.clear();
		for (int i = 0; i < nb; i++)ma[d2[i]]++;
		int now = nb;
		for (int l = k; l < na; l += kai)
		{
			now -= abs(ma[d1[l]]);
			ma[d1[l]]--;
			now += abs(ma[d1[l]]);
			if (l / kai >= nb)
			{
				now -= abs(ma[d1[l - kai*nb]]);
				ma[d1[l - kai*nb]]++;
				now += abs(ma[d1[l - kai*nb]]);
			}
			if (now == 0)ans.push_back(l - kai *(nb - 1) + 1);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]); printf("\n");
}