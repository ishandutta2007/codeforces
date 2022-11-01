/*
  !










*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
ll getPrime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			while (x % i == 0) x /= i;
			if (x == 1) re i;
			re -1;
		}
	}
	if (x == 1) re -1;
	re x;
}
ll dp[2][100007];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ll x;
	scanf("%lld", &x);
	vector<ll> divs;
	for (ll i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{	
			divs.push_back(i);
			if (x / i != i)
			{
				divs.push_back(x / i);
			}
		}
	}
	sort(divs.begin(), divs.end());
	map<ll, vector<ll> > go;
	map<ll, ll> pos;
	for (int i = 0; i < (int)divs.size(); i++)
	{
		pos[divs[i]] = i;
	}
	for (int i = 1; i < (int)divs.size(); i++)
	{
		ll curPrime = getPrime(divs[i] - 1);
		if (curPrime != -1)
		{
	//		cerr << curPrime << " " << divs[i] << endl;
			go[curPrime].push_back(divs[i]);
		}
	}
	int dcnt = (int)divs.size();
	dp[0][0] = 1;
	int lst = 0, cur = 1;
	for (auto it = go.begin(); it != go.end(); ++it)
	{
		for (int j = 0; j <= dcnt; j++)
		{
			dp[cur][j] = 0;
		}
		vector<ll> curd = (*it).second;
		for (int j = 0; j < dcnt; j++)
		{
			if (dp[lst][j] == 0) continue;
			dp[cur][j] += dp[lst][j];
			for (int k = 0; k < (int)curd.size(); k++)
			{
				ll xx = divs[j] * curd[k];
				if (xx <= x && pos.count(xx))
				{
					dp[cur][pos[xx]] += dp[lst][j];
				}
			}
		}
		swap(cur, lst);
	}
	printf("%lld\n", dp[lst][dcnt - 1]);
}