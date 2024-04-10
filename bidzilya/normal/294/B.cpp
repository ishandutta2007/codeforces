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

int n;
vector<vector<int> > a;

int main()
{
	a.resize(2);
	cin >> n;
	int W = 0;
	for (int i=0; i<n; i++)
	{
		int t,w;
		cin >> t >> w;
		t--;
		a[t].push_back(w);
		W += w;
	}
	sort(a[0].begin(),a[0].end());
	sort(a[1].begin(),a[1].end());
	int ans=2*n;
	for (int c1=0; c1<=a[0].size(); c1++)
		for (int c2=0; c2<=a[1].size(); c2++)
		{
			int cans = c1 + 2*c2;
			int cw=0;
			for (int i=a[0].size()-c1; i<a[0].size(); i++)
				cw += a[0][i];
			for (int i=a[1].size()-c2; i<a[1].size(); i++)
				cw += a[1][i];
			if (cans >= W-cw)
				ans = min(ans,cans);
		}
	cout << ans << endl;
	return 0;
}