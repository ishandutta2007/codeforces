#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <memory.h>
#include <utility>
#include <cctype>
#include <complex>
#include <fstream>
#include <sstream>
#include <climits>
using namespace std;

#define ll long long
#define mod 1000000007
#define infinity (ll)1e8
#define epsilon 1e-7

#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pii pair<int,int>
#define MP make_pair
#define PB push_back

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(ll i = (b) - 1; i >= a; --i)
#define REPEAT(n) FOR(counter, 0, (n))
/*
int n, m;
//cin >> n >> m;

int xx, yy;
vector<int> edges[150001];

map<pair<int, int>, bool> mp;

bool check(int v)
{
	for (int i = 0; i < edges[v].size(); i++)
		for (int j = i + 1; j < edges[v].size(); j++)
			if (i != j && !(mp[make_pair(edges[v][i], edges[v][j])] || mp[make_pair(edges[v][j], edges[v][j])]))
				return true;

	return false;
}

set<int> v;
set<int>::iterator it;
*/

string a[51] = { "Aaa","Aaq", "Aaz", "Aaw", "Aas", "Aax", "Aae", "Aad", "Aac", "Aar", "Aaf", "Aav", "Aat", "Aag", "Aab", "Aay", "Aah", "Aan", "Aau", "Aaj", "Aam", "Aai", "Aak", "Aao",
"Aala", "Apaa", "Aqaa", "Aaaa", "Azaa", "Awaa", "Asaa", "Axaa", "Aeaa", "Adaa", "Acaa", "Araa", "Afaa", "Avaa", "Ataa", "Agaa", "Abaa", "Ayaa", "Ahaa", "Anaa", "Auaa", "Ajaa", "Amaa", "Aiaa", "Akaa", "Aoaa", "Alaa" };

string jyn[100];

int main()
{
	int n, k;
	cin >> n >> k;

	FOR(i, 0, n - k + 1)
		cin >> jyn[i];
	queue<string> q;
	for (int i = 0; i < k-1; i++)
	{
		cout << a[i] << " ";
		q.push(a[i]);
	}
	int pos = k;
	for (int i = 0; i < n - k + 1; i++)
	{
		if (jyn[i] == "YES")
		{
			cout << a[pos] << " ";
			q.pop();
			q.push(a[pos]);
			pos++;
		}
		else
		{
			string w = q.front();
			cout << w << " ";
			q.pop();
			q.push(w);
		}
	}





	return 0;
}