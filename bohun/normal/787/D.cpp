#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 1000005, mod = 1e9 + 7;
const ll inf = 1e18;
int n, qq, s;
int w, l, r, u, v;
vector <pair<int, int>> e[nax];	
int j = (1 << 17);
int A = j + 1, B = 3 * j + 5;
ll dp[nax];
bool odw[nax];
priority_queue <pair<ll, int>> q;
void add(int node, int type)
{
	if(type == 2)
	{
		node += A;
		e[v + j + A].pb(mp(node, w));
	}
	if(type == 3)
	{
		node += B;
		e[node].pb(mp(v + j + A, w));
	}
}
void go(int x, int y, int type, int node = 1, int lewo = 0, int prawo = j - 1)
{
	if(y >= prawo && lewo >= x)
	{
		add(node, type);
		return ;
	}
	int mid = (lewo + prawo) / 2;
	if(x <= mid)
		go(x, y, type, node * 2, lewo, mid);
	if(y > mid)
		go(x, y, type, node * 2 + 1, mid + 1, prawo);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> qq >> s;
	s--;
	while(qq--)
	{
		int t;
		cin >> t;
		cin >> v >> l >> r;
		v--;
		l--;
		r--;
		if(t == 1)
		{
			e[v].pb(mp(l, r + 1));
		}
		else
		{
			cin >> w;
			go(l, r, t);
		}
	}
	for(int i = 1; j > i; ++i)
	{
		int node = i + A;
		e[node].pb(mp(i * 2 + A, 0));
		e[node].pb(mp(i * 2 + 1 + A, 0));
		node = i + B;
		e[i * 2 + B].pb(mp(node, 0));
		e[i * 2 + 1 + B].pb(mp(node, 0));
	}
	for(int i = 0; n > i; ++i)
	{
		int s = j + i + A;
		int ss = j + i + B;
		e[s].pb(mp(i, 0));
		e[i].pb(mp(s, 0));
		e[ss].pb(mp(i, 0));
		e[i].pb(mp(ss, 0));
	}
		
		
	for(int i = 0; 800000 > i; ++i)
		dp[i] = inf;
	dp[s] = 0;
	q.push(mp(0, s));
	while(!q.empty())
	{
		int node = q.top().se;
		q.pop();
		if(odw[node])
			continue;
		odw[node] = 1;
		for(auto it: e[node])
		{
			if(dp[it.fi] > dp[node] + it.se)
			{
				dp[it.fi] = dp[node] + it.se;
				q.push(mp(-dp[it.fi], it.fi));
			}
		}
	}
	for(int i = 0; n > i; ++i)
		cout << (dp[i] != inf ? dp[i] : -1) << " ";
		
	
	
			
	
		
		
    return 0;
}