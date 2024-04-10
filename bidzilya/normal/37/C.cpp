#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	vector<string> v(1111);
	int sz=2;
	v[0]="0";
	v[1]="1";
	vector<string> ans(n);
	for (int i=1; i<=1000; i++)
	{
		for (int j=0; j<n; j++)
			if (a[j]==i)
			{
				if (sz==0){cout << "NO" << endl; return 0;}
				ans[j]=v[--sz];
			}
		for (int j=0; j<sz; j++)
		{
			if (sz+j < 1000)
				v[sz+j]=v[j]+"1";
			v[j]+="0";
		}
		sz = min(2*sz, 1000);
	}
	cout << "YES" << endl;
	for (int i=0; i<n; i++)
		cout << ans[i] << endl;
	return 0;
}