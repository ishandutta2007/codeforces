#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
typedef bitset<512>bi;
typedef vector<bi>vb;
typedef pair<vb, vb>pvv;
pvv tim(pvv a, pvv b)
{
	bi z;
	for (int i = 0; i < 512; i++)z[i] = 0;
	pvv ret;
	ret.first.resize(512);
	ret.second.resize(512);
	for (int i = 0; i < 512; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			if (z != (a.first[i] & b.second[j]))ret.first[i][j] = ret.second[j][i] = 1;
		}
	}
	return ret;
}
pvv dat[70][2];
typedef long long ll;
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	dat[0][0].first.resize(512);
	dat[0][0].second.resize(512);
	dat[0][1].first.resize(512);
	dat[0][1].second.resize(512);
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		dat[0][zc].first[zb][za] = dat[0][zc].second[za][zb] = 1;
	}
	for (int i = 1; i <= 60; i++)dat[i][0] = tim(dat[i - 1][1], dat[i - 1][0]), dat[i][1] = tim(dat[i - 1][0], dat[i - 1][1]);
	int maxi = -1;
	for (int i = 0; i <= 60; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 512; j++)cnt += dat[i][0].first[j][0];
		if (cnt > 0)maxi = i;
	}
	if (maxi == -1)
	{
		printf("0\n");
		return 0;
	}
	ll ans = 1LL << maxi;
	pvv now = dat[maxi][0];
	int cur = 1;
	for (int i = maxi - 1; i >= 0; i--)
	{
		pvv z = tim(dat[i][cur], now);
		int cnt = 0;
		for (int j = 0; j < 512; j++)cnt += z.first[j][0];
		if (cnt > 0)now = z, cur = 1 - cur, ans += 1LL << i;
	}
	if (ans > 1000000000000000000LL)ans = -1;
	printf("%I64d\n", ans);
}