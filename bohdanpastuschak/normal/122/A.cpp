#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ll unsigned long long
#define mod 1000000007

int main()
{
	int n;
	cin >> n;


	int arr[] = { 4,7,47,74,44,77,444,474,447,477,777,744,747,774 };
	for (int i = 0; i < 14; ++i)
		if (n%arr[i] == 0)
		{
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}