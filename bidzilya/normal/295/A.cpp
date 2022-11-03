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

int n,m,k;
vector<ll> a,addm,addk,d;
vector<int> l,r;

int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	cin >> n >> m >> k;
	l.resize(m+10);
	r.resize(m+10);
	d.resize(m+10);
	a.resize(n+10);
	addm.resize(n+10);
	addk.resize(m+10);
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=m; i++)
		cin >> l[i] >> r[i] >> d[i];
	for (int i=0; i<k; i++)
	{
		int x,y;
		cin >> x >> y;
		addk[x]++;
		addk[y+1]--;
	}
	ll c=0;
	for (int i=1; i<=m; i++)
	{
		c += addk[i];
		addm[l[i]] += c*d[i];
		addm[r[i]+1] -= c*d[i];
	}
	c=0;
	for (int i=1; i<=n; i++)
	{
		c += addm[i];
		cout << a[i]+c << " ";
	}
	cout << endl;	
	
	return 0;
}