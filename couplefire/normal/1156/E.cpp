#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int lf[N];
int rg[N];
int n;
int ans = 0;
int p[N];
int q[N];

void update(int l, int r, int l2, int r2, int sum)
{
	for(int i = l; i <= r; i++)
	{
		int o = sum - p[i];
		if(o >= 1 && o <= n && l2 <= q[o] && q[o] <= r2)
			ans++;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		q[p[i]] = i;
	}
	stack<pair<int, int> > s;
	s.push(make_pair(n + 1, -1));
	for(int i = 0; i < n; i++)
	{
		while(s.top().first < p[i])
			s.pop();
		lf[i] = s.top().second;
		s.push(make_pair(p[i], i));
	}
	while(!s.empty())
		s.pop();
	s.push(make_pair(n + 1, n));
	for(int i = n - 1; i >= 0; i--)
	{
		while(s.top().first < p[i])
			s.pop();
		rg[i] = s.top().second;
		s.push(make_pair(p[i], i));
	}
	for(int i = 0; i < n; i++)
	{
	//	cerr << i << " " << lf[i] << " " << rg[i] << endl;
		int lenl = i - lf[i] - 1;
		int lenr = rg[i] - i - 1;
		if(lenl == 0 || lenr == 0)
			continue;
		if(lenl < lenr)
			update(lf[i] + 1, i - 1, i + 1, rg[i] - 1, p[i]);
		else
			update(i + 1, rg[i] - 1, lf[i] + 1, i - 1, p[i]);
	}
	cout << ans << endl;
}