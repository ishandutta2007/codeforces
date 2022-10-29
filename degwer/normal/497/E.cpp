#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
typedef vector<vector<ll> >vvi;
typedef pair<vvi, vector<ll> >pvv;
int num;
pvv merge(vvi a, vvi b, vector<ll>ta, vector<ll>tb, int stp)
{
	vvi ret;
	ret.resize(num);
	for (int i = 0; i < num; i++)ret[i].resize(num);
	vector<ll>tr = ta;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			for (int k = 0; k < num; k++)
			{
				ret[i][k] += a[i][j] * b[(j + num - stp) % num][(k + num - stp) % num];
				ret[i][k] %= mod;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			tr[i] += a[i][j] * tb[(j + num - stp) % num];
			tr[i] %= mod;
		}
	}
	return make_pair(ret, tr);
}
vvi dat[100];
vector<ll>td[100];
int main()
{
	ll len;
	scanf("%I64d%d", &len, &num);
	dat[0].resize(num);
	for (int i = 0; i < num; i++)dat[0][i].resize(num);
	for (int i = 0; i < num; i++)dat[0][0][i] = dat[0][i][i] = 1;
	td[0].resize(num);
	td[0][0] = 1;
	vvi e;
	e.resize(num);
	for (int i = 0; i<num; i++)e[i].resize(num);
	for (int i = 0; i<num; i++)e[i][i] = 1;
	vector<ll>te;
	te.resize(num);
	ll now = 1;
	for (int p = 1;; p++)
	{
		if (double(now)*double(num)>(2e18))break;
		now *= num;
		vvi z = e;
		vector<ll>t = te;
		for (int i = 0; i < num; i++)
		{
			pvv x = merge(z, dat[p - 1], t, td[p - 1], i);
			z = x.first;
			t = x.second;
		}
		dat[p] = z;
		td[p] = t;
	}
	/*for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%I64d ", dat[2][i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < num; i++)printf("%I64d ", td[2][i]); printf("\n");*/
	vector<int>v;
	for (;;)
	{
		if (len == 0)break;
		v.push_back(len%num);
		len /= num;
	}
	vvi n = e;
	vector<ll>tn = te;
	for (int i = int(v.size()) - 1; i >= 0; i--)
	{
		for (int j = 0; j < v[i]; j++)
		{
			int d = j;
			for (int k = int(v.size()) - 1; k >= i + 1; k--)d += v[k];
			d %= num;
			pvv z = merge(n, dat[i], tn, td[i], d);
			n = z.first;
			tn = z.second;
		}
	}
	ll ans = 1;
	for (int i = 0; i < num; i++)ans += tn[i];
	printf("%I64d\n", ans%mod);
}