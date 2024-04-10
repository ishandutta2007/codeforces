#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rep0(i, n) for(int i = (0); i < (n); i++)
#define repd(i,m,n) for(int i=(m); i > (n); i--)
#define iter(el, arr) for(auto& el : arr)
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()

#define ld long double
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define plli pair<pll,int>
#define MP make_pair
#define SZ(a) int((a).size())
#define X first
#define Y second

#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define vi vector<int>
#define vll vector<ll>
#define vch vector<char>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vb vector<bool>
#define vvb vector<vb>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define pq priority_queue
#define mod 1000000007
using namespace std;

const ll INF = 1e18;
const ll MAXN = 501;

string s, t;

map<char, ll> in_s;
map<char, ll> in_t;

bool can(ll n)
{
	ll add = 0;

	ll ye, sh;
	for (auto k : in_t)
	{
		ye = in_s[k.first];
		sh = k.second*n;
		if (sh > ye)
			add += (sh - ye);
	}

	return (add <= in_s['?']);
}

ll bin(ll l, ll r)
{
	if (r - l <= 1)
		if (can(r))
			return r;
		else
			return l;
	ll m = (l + r) / 2;
	if (can(m))
		return bin(m, r);
	else
		return bin(l, m);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	//freopen("In.txt", "r", stdin);

	
	cin >> s >> t;

	
	FOR(i, 0, s.size())
		in_s[s[i]]++;

	FOR(i, 0, t.size())
		in_t[t[i]]++;


	ll ch = bin(0, 1000000);

	multiset<char> she;
	ll ye, sh;
	for (auto k : in_t)
	{
		ye = in_s[k.first];
		sh = k.second*ch;
		if (sh > ye)
		{
			FOR(i,0,sh - ye)
				she.insert(k.first);
		}
	}

	FOR(i, 0, s.size())
		if (s[i] != '?')
			cout << s[i];
		else
		{
			if (she.size() > 0)
			{
				cout << *she.begin();
				she.erase(she.begin());
			}
			else
				cout << 'a';
		}

	return 0;
}
//don't forget about MAXN, mod and INF