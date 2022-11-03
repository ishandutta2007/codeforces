#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int module = 1e9+7;
const int base = 31;
const int LIM = 3*1e5 + 10;

typedef unsigned int uint;

int n;
vector<vector<int> > g;
vector<vector<string> > s;
vector<ll> h1;
vector<int> h2;
string t;
ll ans=0;
int l=0;

ll H1;
int H2;

vector<ll> pow1;
vector<int> pow2;

void add(char c)
{
	h1[l] = pow1[l]*(c-'a'+1);
	if (l!=0)h1[l] += h1[l-1];

	h2[l] = (1LL*pow2[l]*(c-'a'+1))%module;
	if (l!=0)h2[l] = (h2[l]+h2[l-1])%module;

	l++;
}

void check()
{
	if (l < t.length())return;
	if (l == t.length() && h1[l-1]==H1 && h2[l-1]==H2)
		ans++;
	else
	if (l > t.length())
	{
		ll th1 = H1*pow1[l-t.length()];
		int th2 = (1LL*H2*pow2[l-t.length()])%module;
		
		if (th1 == h1[l-1]-h1[l-t.length()-1] && 
			th2 == (h2[l-1]-h2[l-t.length()-1]+module)%module)
				ans++;
	}
}

void dfs(int v, int pr=-1)
{
	for (int i=0; i<g[v].size(); i++)
	{
		int u = g[v][i];
		if (u!=pr)
		{
			for (int j=0; j<s[v][i].length(); j++)
			{
				add(s[v][i][j]);
				check();
			}
			dfs(u, v);
			l -= s[v][i].length();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	cin >> n;
	g.resize(n+1);
	s.resize(n+1);
	for (int i=2; i<=n; i++)
	{
		int p;
		cin >> p >> t;
		g[p].push_back(i);
		s[p].push_back(t);
	}
	cin >> t;
	h1.resize(LIM);
	h2.resize(LIM);
	pow1.resize(LIM);
	pow2.resize(LIM);
	H1 = 0;
	H2 = 0;
	pow1[0]=pow2[0]=1;
	for (int i=1; i<LIM; i++)
	{
		pow1[i] = pow1[i-1]*base;
		pow2[i] = (1LL*pow2[i-1]*base)%module;
	}
	for (int i=0; i<t.length(); i++)
	{
		H1 += pow1[i]*(t[i]-'a'+1);
		H2 = (H2 + (1LL*pow2[i]*(t[i]-'a'+1))%module)%module;
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}