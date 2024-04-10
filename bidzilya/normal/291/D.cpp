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

typedef unsigned int uint;

int n,k;

int main()
{
	ios_base::sync_with_stdio(0);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	cin >> n >> k;
	int c=1;
	
	while (k)
	{
		for (int i=1; i<=n; i++)
			cout << min(i+c, n) << " ";
		c *= 2;
		k--;
		cout << endl;
	}
	return 0;
}