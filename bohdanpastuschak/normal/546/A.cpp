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
	ll n, k, w;
	cin >> k>> n >> w;

	if (n > k*(w*(w + 1)) / 2)cout << 0;
	else cout << k*(w*(w + 1)) / 2 - n;
	
	return 0;
}