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
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n,k;
	cin >> n >> k;
	bool may = true;
	int cn = 0;
	for (int i=0; i<n; i++)
	{
		char c;
		cin >> c;
		if (c=='.')
			cn = 0;
		else
			cn++;
		if (cn >= k)
			may = false;
	}
	cout << (may?"YES":"NO") << endl;
	return 0;
}