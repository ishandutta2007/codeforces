#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <map>
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
typedef pair<ll, int> pii;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n,m;
	cin >> n >> m;
	int e1=0;
	for (int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		if (a==1)e1++;
	}
	int e2=n-e1;
	for (int i=0; i<m; i++)
	{
		int l,r;
		cin >> l >> r;
		int c=r-l+1;
		if (c%2!=0)
			cout << 0;
		else
		{
			c /= 2;
			if (e1 >= c && e2 >= c)
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}
	return 0;
}