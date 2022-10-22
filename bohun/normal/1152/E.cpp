#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;
const int nax = 200005;
stack <int> s;
int wsk[nax];
bool Epath(int n, vector <pair<int, int>> (&v)[nax], bool (&odw)[nax], vector <int> &ans)
{
	int a = -1, b = -1;
	for(int i = 0; n > i; ++i)
	{
		if(ss(v[i]) & 1)
		{
			if(a == -1)
				a = i;
			else if(b == -1)
				b = i;
			else
				return 0;
		}
	}
	if(a != -1)
	{
		v[a].pb({b, nax - 1});
		v[b].pb({a, nax - 1});
	}
	int fi = a;
	if(fi == -1)
		fi = 0;
	s.push(fi);
	while(!s.empty())
	{
		int node = s.top();
		int u = -1;
		for(; wsk[node] < ss(v[node]); ++wsk[node])
		{
			u = v[node][wsk[node]].fi;
			int byl = v[node][wsk[node]].se;
			if(!odw[byl])
			{
				odw[byl] = 1;
				break;
			}
		}
		if(wsk[node] == ss(v[node]))
		{
			ans.pb(node);
			s.pop();
		}
		else
		{
			s.push(u);
		}
	}
	if(a != -1)
	{
		vector <int> nowe;
		for(int i = 0; ss(ans) > i; ++i)
		{
			int c = ans[i];
			int d = ans[i + 1];
			if((a == c && b == d) || (a == d && c == b))
			{
				for(int j = i + 1; ss(ans) > j; ++j)
					nowe.pb(ans[j]);
				for(int j = 1; i >= j; ++j)
					nowe.pb(ans[j]);
				break;
			}
		}
		ans = nowe;
	}
	return 1;	
}


int n;
int b[nax], c[nax];
map <int, int> mapa, odp;
vector <int> val;
bool odw[nax];
vector <pair< int, int>> v[nax];
vector <int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; n - 1 >= i; ++i)
		cin >> b[i], val.pb(b[i]);
	for(int i = 1; n - 1 >= i; ++i)
		cin >> c[i], val.pb(c[i]);
	for(int i = 1; n - 1 >= i; ++i)
	{
		if(b[i] > c[i])
		{
			cout << -1;
			return 0;
		}
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for(int i = 0; ss(val) > i; ++i)
		mapa[val[i]] = i, odp[i] = val[i];
	for(int i = 1; n - 1 >= i; ++i)
	{
		b[i] = mapa[b[i]];
		c[i] = mapa[c[i]];
		v[b[i]].pb({c[i], i});
		v[c[i]].pb({b[i], i});
	}
	bool ok = Epath(ss(val), v, odw, ans);
	if(!ok || ss(ans) < n)
	{
		cout << -1;
	}
	else
	{
		for(auto it: ans)
			cout << odp[it] << " ";
	}
	
	
	
	return 0;
}