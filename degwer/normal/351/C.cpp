#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> >mat;
ll INF = 2100000000;
mat e;
void makee(int n)
{
	e.clear();
	e.resize(n);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			e[i].push_back(0);
		}
	}
}
mat tim(mat a, mat b)
{
	mat ret;
	ret.resize(a.size());
	for (int i = 0; i < a.size(); i++)ret[i].resize(b[0].size());
	for (int i = 0; i < a.size(); i++)for (int j = 0; j < a.size(); j++)ret[i][j] = INF;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b[0].size(); j++)
		{
			for (int k = 0; k < a[0].size(); k++)
			{
				ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return ret;
}
mat po(mat a, ll b)
{
	if (b == 1)return a;
	mat z = po(a, b / 2);
	z = tim(z, z);
	if (b % 2 == 1)z = tim(z, a);
	return z;
}
int a[20], b[20];
#define B 40
int main()
{
	int num, len;
	scanf("%d%d", &num, &len);
	for (int i = 0; i < num; i++)scanf("%d", &a[i]);
	for (int i = 0; i < num; i++)scanf("%d", &b[i]);
	makee(B + 1);
	mat m = e;
	for (int i = 0; i <= B; i++)for (int j = 0; j <= B; j++)m[i][j] = INF;
	for (int p = 0; p < (1 << num); p++)
	{
		int s = 0, r = 0;
		int sum = 0;
		for (int i = 0; i < num; i++)
		{
			if (p&(1 << i))s++, sum += a[i];
			else s--, sum += b[i];
			r = min(r, s);
		}
		for (int i = -r; i <= B - max(0, s); i++)m[i][i + s] = min(m[i][i + s], (ll)sum);
		//printf("%d %d %d %d\n", p, s, r, sum);
	}
	m = po(m, len);
	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)printf("%I64d ", m[i][j]); printf("\n");
	}*/
	printf("%I64d\n", m[0][0]);
}