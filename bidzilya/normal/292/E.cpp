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

const int module = 1e9+7;

int n,m;

const int INF = 1e9;

vector<int> a,b;
vector<int> t;

void push(int v)
{
	if (t[v] != INF)
	{
		t[v*2] = t[v*2+1] = t[v];
		t[v] = INF;
	}
}

void update(int v, int tl, int tr, int l, int r, int d)
{
	if (l > r)
		return;
	if (l==tl && tr==r)
		t[v] = d;
	else
	{
		push(v);
		int tm = (tl+tr)/2;
		update(v*2, tl, tm, l, min(r,tm), d);
		update(v*2+1, tm+1, tr, max(l,tm+1), r, d);
	}
}

int get(int v, int tl, int tr, int p)
{
	if (tl==tr)
		return t[v];
	push(v);
	int tm=(tl+tr)/2;
	if (p <= tm)
		return get(v*2, tl, tm, p);
	else
		return get(v*2+1, tm+1, tr, p);
}

void build(int v, int tl, int tr)
{
	t[v] = INF;
	if (tl!=tr)
	{
		int tm=(tl+tr)/2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];
	t.resize(n*4+10);

	build(1, 0, n-1);
	for (;m;m--)
	{
		int t;
		cin >> t;
		if (t==1)
		{
			int x,y,k;
			cin >> x >> y >> k;
			x--;y--;

			update(1, 0, n-1, y, y+k-1, x-y);
		}else
		{
			int x;
			cin >> x;
			x--;
			int dx = get(1, 0, n-1, x);
			if (dx == INF)
				cout << b[x] << endl;
			else
				cout << a[x+dx] << endl;
		}
	}



	return 0;
}