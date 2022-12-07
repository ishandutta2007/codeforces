#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<list>
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323
#define MOD 10007
using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
int a[500];
int main() {
	int n;
	ll k;
	scanf("%d%I64d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	if (k >= n)
	{
		printf("%d", n);
		return 0;
	}
	else
	{
		int cnt = 0, now = a[0];
		for (int i = 0; i <= n; i++)
		{
			if (i == n) i = 0;
			if (a[i] == now)continue;
			if (now > a[i])
			{
				cnt++;
				if ((ll)cnt == k)
				{
					printf("%d", now);
					return 0;
				}
			}
			else
			{
				now = a[i];
				cnt = 1;
			}
		}
	}
}