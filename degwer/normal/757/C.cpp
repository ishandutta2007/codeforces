#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
vector<int>dat[1000000];
int main()
{
	int num, ko;
	scanf("%d%d", &num, &ko);
	int pt = 0;
	for (int i = 0; i < num; i++)
	{
		int n;
		scanf("%d", &n);
		vector<int>v;
		for (int j = 0; j < n; j++)
		{
			int z;
			scanf("%d", &z);
			z--;
			v.push_back(z);
		}
		sort(v.begin(), v.end());
		v.push_back(-1);
		int now = v[0], cnt = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (now != v[j])
			{
				dat[now].push_back(pt + cnt);
				now = v[j];
				cnt = 1;
			}
			else cnt++;
		}
		pt += n + 1;
	}
	for (int i = 0; i < ko; i++)sort(dat[ko].begin(), dat[ko].end());
	sort(dat, dat + ko);
	ll ans = 1;
	ll now = 1;
	for (int i = 1; i < ko; i++)
	{
		if (dat[i] == dat[i - 1])now++;
		else now = 1;
		ans = ans*now%mod;
	}
	printf("%I64d\n", ans);
}