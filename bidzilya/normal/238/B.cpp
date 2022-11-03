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
	int n,h;
	cin >> n >> h;
	if (n==2)
	{
		cout << 0 << endl << 2 << " " << 2 << endl;
		return 0;
	}
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	int mn=0;
	for (int i=1; i<n; i++)
		if (a[i]<a[mn])mn=i;
	sort(a.begin(), a.end());
	int ans1=a[n-1]+a[n-2]-a[0]-a[1];
	int ans2=max(a[0]+a[n-1]+h,a[n-1]+a[n-2])-min(a[0]+a[1]+h,a[1]+a[2]);
	if (ans2>=ans1)mn=n;
	cout << min(ans1,ans2) << endl;
	for (int i=0; i<n; i++)
		cout << (1+(mn==i)) << " ";
	cout << endl;
	return 0;
}