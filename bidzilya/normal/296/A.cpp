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
int a[1111];

int main()
{
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	cin >> n;
	for (int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
		if (a[x] > (n+1)/2)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}