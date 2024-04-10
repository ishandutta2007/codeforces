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
	int a, b, c;
	cin >> a >> b >> c;
	
	int d = a*b*c;
	d = max(d, a + b + c);
	d = max(d, (a + b)*c);
	d = max(d, a * (b + c));
	cout << d;
	return 0;
}