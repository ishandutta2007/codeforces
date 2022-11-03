#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

bool cmpPair(const pii& a, const pii& b)
{
	return (a.first < b.first);
}

int n,m,k;
vector<pii> a,b;

void build(vector<pii>& a, int& n)
{
	sort(a.begin(), a.end(), cmpPair);
	int j=0;
	for (int i=1; i<a.size(); i++)
		if (a[i].first==a[j].first)
			a[j].second += a[i].second;
		else
		{
			j++;
			a[j].second = a[i].second;
			a[j].first = a[i].first;
		}
	n = j+1;
	a.resize(n);
}

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	cin >> n >> m >> k;
	a.resize(n+m);
	for (int i=0; i<n; i++)
	{
		cin >> a[i].first;
		a[i].second = 1;
	}
	b.resize(m+n);
	for (int i=0; i<m; i++)
	{
		cin >> b[i].first;
		b[i].second = 1;
	}
	for (int i=0; i<n; i++)
	{
		b[i+m].first = a[i].first;
		b[i+m].second = 0;
	}
	for (int i=0; i<m; i++)
	{
		a[i+n].first = b[i].first;
		a[i+n].second = 0;
	}
	build(a, n);
	build(b, m);

	while (n > 0 && m > 0)
		if (a[n-1].second > b[m-1].second)
		{
			cout << "YES" << endl;
			return 0;
		}else
		{
			n--;
			m--;
			if (n > 0)
				a[n-1].second += a[n].second;
			if (m > 0)
				b[m-1].second += b[m].second;
		}
	cout << "NO" << endl;
	return 0;
}