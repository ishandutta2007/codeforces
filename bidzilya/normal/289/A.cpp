

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
	long long cnt=0;
	for (int i=0; i<n; i++)
	{
		int l,r;
		cin >> l >> r;
		cnt += (r-l+1);
	}
	cout << (k-cnt%k)%k << endl;
	return 0;
}