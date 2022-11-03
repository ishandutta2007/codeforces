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
using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n,k;
	cin >> n >> k;
	for (int i=k+1; i>=1; i--)
		cout << i << " ";
	for (int i=k+2; i<=n; i++)
		cout << i << " ";
	cout << endl;
	return 0;
}