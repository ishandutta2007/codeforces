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
const int module = 1e9+7;

const int ans[16]={1,0,3,0,15,0,133,0,2025,0,37851,0,1030367,0,36362925,0};
int n;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n;
	int a=ans[n-1]%module;
	for (int i=2; i<=n; i++)
		a=(1LL*i*a)%module;
	cout << a << endl;
	return 0;
}