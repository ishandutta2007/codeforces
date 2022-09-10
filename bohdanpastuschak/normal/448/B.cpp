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
#include <tuple>

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define ld long double
#define ll long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) ll((a).size())
#define X first
#define Y second

#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define pq priority_queue
#define mod 1000000007
#define PI 3.141592653589793
using namespace std;

const ll INF = 1e18;
const ll MAXN = 101;

vi pref(string s)
{
	int n = (int)s.length();
	vi pi(n);
	int j;
	FOR(i,1,n)
	{
		j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			++j;
		pi[i] = j;
	}
	return pi;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("strings.in", "r", stdin);
	//freopen("strings.out", "w", stdout);

	string s, t;
	cin >> s >> t;

	int curr1 = 0, curr2 = 0;
	while (curr1 < s.size() && curr2 < t.size())
		if (s[curr1] == t[curr2])
			curr2++, curr1++;
		else
			curr1++;

	if (curr2 == t.size())
	{
		cout << "automaton";
		return 0;
	}

	if (s.size() == t.size())
	{
		map<char, int> m1, m2;
		FOR(i, 0, s.size())
			m1[s[i]]++, m2[t[i]]++;

		bool was = true;
		for (auto i : m1)
			if (i.second != m2[i.first])
				was = false;
		if (was)
		{
			cout << "array";
			return 0;
		}
	}

	map<char, int> m1, m2;
	FOR(i, 0, s.size())
		m1[s[i]]++;
	FOR(i, 0, t.size())
		m2[t[i]]++;

	for(auto i: m2)
		if (i.second > m1[i.first])
		{
			cout << "need tree";
			return 0;
		}

	cout << "both";
	return 0;
}