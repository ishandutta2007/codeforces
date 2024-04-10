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

int a[111];
int n;

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	for (int i=0; i<m; i++)
	{
		int x,y;
		cin >> x >> y;
		if (x!=1)
			a[x-1] += y-1;
		if (x!=n)
			a[x+1] += a[x]-y;
		a[x] = 0;
	}
	for (int i=1; i<=n; i++)
		cout << a[i] << endl;
	return 0;
}