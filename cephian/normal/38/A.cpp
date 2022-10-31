#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

int n,a,b;
int d[105];

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i < n; ++i)
		cin >> d[i];
	cin >> a >> b;
	int c = 0;
	for(int i = a; i < b; ++i)
		c += d[i];
	cout << c << "\n";
	return 0;
}