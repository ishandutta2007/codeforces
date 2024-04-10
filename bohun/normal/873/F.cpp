#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
using namespace std;
int n;
const int nax = 200005;
char a[nax], b[nax], c[nax], d[nax];
int kmr[nax][18];
int lcp[nax];
int order[nax], num[nax];
int pref[nax];
int D[nax], G[nax];
void gokmr()
{
	for(int i = 1; n >= i; ++i)
		kmr[i][0] = c[i] - 'a';
	int g = ceil((ld)log2(n));
	for(int i = 1; g >= i; ++i)
	{
		vector < pair < pair < int, int >, int > > help;
		int pot = (1 << (i - 1));
		for(int j = 1; n >= j; ++j)
			{
				if(j + pot > n)
					help.pb({{kmr[j][i - 1], -1}, j});
				else
					help.pb({{kmr[j][i - 1], kmr[j + pot][i - 1]}, j});
			}
		sort(help.begin(), help.end());
		pair < int, int > last = {-1, -1};
		int id = -1;
		for(auto it: help)
		{
			if(last != it.fi)
				id++;
			kmr[it.se][i] = id;
			last = it.fi;
		}
	}	
	for(int i = 1; n >= i; ++i)
	{
		order[kmr[i][g]] = i;
		num[i] = kmr[i][g];
	}
}
void golcp()
{
	int k = 0;
	for(int i = 1; n >= i; ++i)
	{
		if(num[i] == n - 1)
			continue;
		int Next = order[num[i] + 1];
		while(Next + k <= n and i + k <= n and c[k + Next] == c[k + i])
			k++;
		lcp[num[i] + 1] = k;
		if(k)
			k--;
	}
}	
int main()
{
	scanf("%d", &n);
	scanf("%s %s", a + 1, d + 1);
	for(int i = 1; n >= i; ++i)
		c[i] = a[n - i + 1], b[i] = d[n - i + 1];
	gokmr();
	golcp();
	for(int i = 1; n >= i; ++i)
		if(b[i] == '1')
			pref[num[i] + 1]++;
	for(int i = 1; n >= i; ++i)
		pref[i] += pref[i - 1];
	stack < pair < int, int > > s;
	lcp[n] = -1;
	for(int i = 1; n >= i; ++i)
		D[i] = G[i] = i;
	for(int i = 1; n >= i; ++i)
	{
		while(!s.empty() && lcp[i] < s.top().fi)
		{
			D[s.top().se] = i;
			s.pop();
		}
		s.push({lcp[i], i});
	}
	while(!s.empty())
		s.pop();
	lcp[0] = -1;
	for(int i = n; i >= 0; --i)
	{
		while(!s.empty() && lcp[i] < s.top().fi)
		{
			G[s.top().se] = i + 1;
			s.pop();
		}
		s.push({lcp[i], i});
	}
	ll ans = 0;
	for(int i = 1; n >= i; ++i)
	{
		ll opt = (ll)lcp[i] * (D[i] - G[i] + 1 - pref[D[i]] + pref[G[i] - 1]);
		ans = max(ans, opt);
	}
	for(int i = 1; n >= i; ++i)
		if(b[i] == '0')
			ans = max(ans, (ll)n - i + 1);
	cout << ans;
	
	
	return 0;
}