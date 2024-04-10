#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long qpow(long long v, long long st, long long p)
{
	long long r = 1;
	while (st)
	{
		if (st&1)
		{
			r *= v;
			if (r >= p) r %= p;
		}
		v = v * v;
		if (v >= p) v %= p;
		st /= 2;
	}
	return r;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int n, m, p;
int a[1<<20], b[1<<20], k[1<<20];
int d;

vector<int> de;
vector< vector<int> > vd;
long long cnt[1<<20];

int pok(int v)
{
	for (int i = 0; i < (int) de.size(); i++)
	{
		if (qpow(v, de[i], p) == 1)
			return de[i];
	}
	//wtf!!
	return -1;
}

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	d = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		d = gcd(d, b[i]);
	}
	d = gcd(d, p-1);
	
	for (int i = 1; i*i <= p-1; ++i)
	{
		if ((p-1)%i == 0)
		{
			de.push_back(i);
			if ((p-1)/i != i)
				de.push_back((p-1)/i);
		}
	}
	sort(de.begin(), de.end());
	
	for (int i = 0; i < n; i++)
	{
		a[i] = qpow(a[i], d, p);
		//~ printf("%d %d\n" , pok(a[i]), d);
		k[i] = pok(a[i]);
		// k[i] e deg.
 	}

	for (int i = 0; i < (int) de.size(); i++)
	{
		vector<int> di;
		for (int j = 0; j < i; ++j)
		{
			if (de[i] % de[j] == 0)
				di.push_back(j);
		}
		vd.push_back(di);
	}
	
	long long ans = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = (int) de.size() - 1; i >= 0; --i)
	{
		int j = 0;
		for (int l = 0; l < n; ++l)
		{
			if (k[l] % de[i] == 0)
				++j;
		}
		if (j > 0)
		{
			long long tk = 1LL - cnt[i];
			ans += tk * de[i];
			for (int j = 0; j < (int) vd[i].size(); ++j)
			{
				cnt[ vd[i][j] ] += tk;
			}
		}
	}
	
	printf("%d\n", (int) ans);
	
	return 0;
}