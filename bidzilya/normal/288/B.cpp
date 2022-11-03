

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

const int module=1e9+7;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n,k;
	cin >> n >> k;
	int res=1;
	for (int i=0; i<k-1; i++)
		res = (1LL*res*k)%module;
	for (int i=0; i<n-k; i++)
		res = (1LL*res*(n-k))%module;
	cout << res << endl;
	return 0;
}