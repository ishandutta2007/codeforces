#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
using namespace std;
#define ll long long

int main()
{
	ll n;
	cin >> n;
	if (n % 2 == 0)cout << n / 2;
	else cout << (-n - 1) / 2;
	return 0;
}