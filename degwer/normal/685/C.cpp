#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define INF 4000000000000000000LL
typedef pair<ll, ll>pii;
pii get(vector<ll>vec)
{
	ll mini = INF, maxi = -INF;
	for (int i = 0; i < vec.size(); i++)
	{
		mini = min(mini, vec[i]);
		maxi = max(maxi, vec[i]);
	}
	return make_pair(maxi, mini);
}
typedef pair<pii, ll>pi3;
ll dat[4][2];
ll ax, ay, az;
bool getv(ll x, ll y, ll z)
{
	if (!(dat[0][0] <= x + y + z&&x + y + z <= dat[0][1]))return false;
	if (!(dat[1][0] <= -x + y + z&&-x + y + z <= dat[1][1]))return false;
	if (!(dat[2][0] <= x - y + z&&x - y + z <= dat[2][1]))return false;
	if (!(dat[3][0] <= x + y - z&&x + y - z <= dat[3][1]))return false;
	ax = x, ay = y, az = z;
	return true;
}
int main()
{
	int data;
	scanf("%d", &data);
	for (int p = 0; p < data; p++)
	{
		int num;
		scanf("%d", &num);
		vector<ll>x, y, z;
		vector<ll>v1, v2, v3, v4;
		for (int i = 0; i < num; i++)
		{
			ll za, zb, zc;
			scanf("%I64d%I64d%I64d", &za, &zb, &zc);
			x.push_back(za);
			y.push_back(zb);
			z.push_back(zc);
			v1.push_back(za + zb + zc);
			v2.push_back(-za + zb + zc);
			v3.push_back(za - zb + zc);
			v4.push_back(za + zb - zc);
		}
		if (num == 1)
		{
			printf("%I64d %I64d %I64d\n", x[0], y[0], z[0]);
			continue;
		}
		pii d[4] = { get(v1), get(v2), get(v3), get(v4) };
		ll beg = 0, end = INF;
		for (;;)
		{
			ll med = (beg + end) / 2;
			for (int i = 0; i < 4; i++)dat[i][0] = d[i].first - med, dat[i][1] = d[i].second + med;
			bool f = false;
			for (int i = 0; i < 4; i++)if (dat[i][0]>dat[i][1])goto l01;
			for (int a = 0; a < 2; a++)
			{
				for (int b = 0; b < 2; b++)
				{
					for (int c = 0; c < 2; c++)
					{
						for (int d = 0; d < 2; d++)
						{
							for (int q = -1; q <= 2; q++)
							{
								for (int r = -1; r <= 2; r++)
								{
									for (int s = -1; s <= 2; s++)
									{
										if (d == 0)f |= getv(((dat[0][a] - dat[1][b]) >> 1) + q, ((dat[0][a] - dat[2][c]) >> 1) + r, ((dat[1][b] + dat[2][c]) >> 1) + s);
										if (c == 0)f |= getv(((dat[0][a] - dat[1][b]) >> 1) + q, ((dat[1][b] + dat[3][d]) >> 1) + r, ((dat[0][a] - dat[3][d]) >> 1) + s);
										if (b == 0)f |= getv(((dat[2][c] + dat[3][d]) >> 1) + q, ((dat[0][a] - dat[2][c]) >> 1) + r, ((dat[0][a] - dat[3][d]) >> 1) + s);
										if (a == 0)f |= getv(((dat[2][c] + dat[3][d]) >> 1) + q, ((dat[1][b] + dat[3][d]) >> 1) + r, ((dat[1][b] + dat[2][c]) >> 1) + s);
										if (f)goto l01;
									}
								}
							}
						}
					}
				}
			}
		l01:;
			if (beg == end)break;
			if (f)end = med;
			else beg = med + 1;
		}
		printf("%I64d %I64d %I64d\n", ax, ay, az);
	}
}