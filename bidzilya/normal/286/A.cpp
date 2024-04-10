#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
vector<int> a;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n;
	if (n%4==2 || n%4==3)
	{
		cout << -1 << endl;
		return 0;
	}
	a.resize(n+1);
	if (n%4==1)
		a[(n+1)/2]=(n+1)/2;
	int l=1,r=n;
	while (r-l>=3)
	{
		a[l]=l+1;
		a[l+1]=r;
		a[r]=r-1;
		a[r-1]=l;
		l+=2;
		r-=2;
	}
	for (int i=1; i<=n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}