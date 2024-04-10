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
	a.resize(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a.begin(),a.end());
	ll ans=0;
	for (int i=0; i<n; i++)
		ans += abs(i+1-a[i]);
	cout << ans << endl;
	return 0;
}