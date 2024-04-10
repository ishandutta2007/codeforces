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

int t[100001],n,m;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		int ci, ti;
		cin >> ci >> ti;
		t[i] = ti*ci;
	}
	int y = 0, time = 1;
	for (int i=0; i<m; i++)
	{
		int ti;
		cin >> ti;
		while (!(ti >= time && ti < time+t[y]))
			time += t[y++];
		cout << y+1 << endl;
	}
	return 0;
}