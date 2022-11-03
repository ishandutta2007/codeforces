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

const int module = 1e9+7;

int n;
vector<int> a,c;

int main()
{
//	ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	cin >> n;
	a.resize(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a.begin(),a.end());
	c.resize(n);
	c[0]=1;
	int j=0;
	for (int i=1; i<n; i++)
		if (a[i]==a[j])
			c[j]++;
		else
		{
			j++;
			c[j]=1;
			a[j]=a[i];
		}
	int p = 0;
	for (int i=0; i<=j; i++)
	{
		if (a[i] == 0)continue;
		if (c[i] > 2)
		{
			cout << -1 << endl;
			return 0;
		}else
		if (c[i] == 2)
			p++;
	}
	cout << p << endl;
	return 0;
}