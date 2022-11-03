#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 222222;

int n,m;
int a[N],u[N],v[N];

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin >> n >> m;
	for (int i=1; i<=n; i++)cin >> a[i];
	u[n]=v[n]=1;
	for (int i=n-1; i>=1; i--)
	{
		if (a[i]<=a[i+1])v[i]=v[i+1]+1;
		else v[i]=1;
		if (a[i]>=a[i+1])u[i]=u[i+1]+1;
		else u[i]=1;
	}
	for (int i=0; i<m; i++)
	{
		int l,r;
		cin >> l >> r;
		if (v[l]>=r-l+1)
			cout << "Yes" << endl;
		else
		if (u[l+v[l]]+v[l]>=r-l+1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}