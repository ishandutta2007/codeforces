#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int A = 1e7;

int del[A+10];
int k;

int decr[A+10];
ll power[A+10];

ll powerIn(ll fact, int n)
{
	ll nn = n;
	ll res = 0;
	while (nn <= fact && nn > 0)
	{
		res += fact/nn;
		nn *= n;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i=2; i<=A; i++)
		if (!del[i])
		{
			del[i] = 1;
			if (1LL*i*i <= A)
				for (int j=i*i; j<=A; j+=i)
					del[j] = i;
		}

	scanf("%d", &k);
	for (int i=0; i<k; i++)
	{
		int a;
		scanf("%d", &a);
		decr[a+1]++;
	}

	for (int i=2; i<=A; i++)
	{
		k -= decr[i];
		
		int x = i;
		while (del[x] > 1)
		{
			power[del[x]] += k;
			x /= del[x];
		}
		if (x > 1)
			power[x] += k;
	}

	ll n = 1;
	for (int i=2; i<=A; i++)
		if (power[i])
		{
			ll cn;
			ll ln=1, rn=1e18;
			while (ln <= rn)
			{
				ll mn = (ln+rn)>>1;
				if (powerIn(mn, i) >= power[i])
				{
					cn = mn;
					rn = mn-1;
				}else
					ln = mn+1;
			}
			n = max(n, cn);
		}
	printf("%I64d\n", n);
					
	return 0;
}