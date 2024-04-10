#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mod 1000000007
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); --i)

#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())
#define infinity (ll)1e18
#define epsilon 1e-6



ll n, k;
vector<ll> g[100001];
bool used[100001];
vector<ll> ans;
ll a[100001];
ll kilk(0);
vector<ll> answ;


void dfs(ll v) {
	used[v] = true;
	for (size_t i = 0; i<g[v].size(); ++i) {
		ll to = g[v][i];
		if (!used[to])
			dfs(to);
	}
	ans.push_back(v);
}

void vsio_po_bratski_po_poniatiam(ll v) {
	ans.clear();
	dfs(v);
}

void p()
{
	kilk += ans.size();
	for (size_t i = 0; i<ans.size(); i++)
		answ.push_back(ans[i]);
}

ll x, xx;

char* cl;
ll cycle_st, cycle_end;
ll* useless;

bool check_dfs(ll v)
{
	cl[v] = 1;
	for (size_t i = 0; i<g[v].size(); ++i) {
		ll to = g[v][i];
		if (cl[to] == 0) {
			useless[to] = v;
			if (check_dfs(to))  return true;
		}
		else if (cl[to] == 1) {
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}

bool isCyclic(ll k)
{
	cycle_st = -1;
	for (ll i = 0; i<k; ++i)
		if (check_dfs(a[i]))
			break;

	if (cycle_st == -1)
		return false;
	else
		return true;

}


int main()
{
	cin >> n >> k;
	cl = new char[n+1];
	useless = new ll[n+1];
	for (ll ii = 0; ii < n + 1; ++ii)
		cl[ii] = 0;

	for (ll i = 0; i<k; i++)
		cin >> a[i];

	for (ll i = 0; i<n; i++)
	{
		cin >> xx;
		for (ll j = 0; j<xx; j++)
		{
			cin >> x;
			g[i + 1].push_back(x);
		}
	}
	if (isCyclic(k))
	{
		cout << -1;
		return 0;
	}
	for (ll i = 0; i<100001; i++)
		used[i] = false;
	for (ll i = 0; i<k; i++)
	{
		if (!used[a[i]])
		{
			vsio_po_bratski_po_poniatiam(a[i]);
			p();
		}
	}
	cout << kilk << endl;
	for (size_t i = 0; i<answ.size(); i++)
		cout << answ[i] << " ";

}