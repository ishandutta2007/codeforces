#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n,k;
	cin >> n >> k;
	if (k>n || k==1 && n>1)
	{
		cout << -1 << endl;
		return 0;
	}
	if (n==1 && k==1)
	{
		cout << 'a' << endl;
		return 0;
	}
	for (int i=0; i<n-k+2; i++)
		cout << (char)('a'+(i%2));
	for (int i=2; i<k; i++)
		cout << (char)('a'+i);
	cout << endl;

	return 0;
}