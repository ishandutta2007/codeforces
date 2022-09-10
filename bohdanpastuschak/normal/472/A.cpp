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

bool isPrime(int n)
{
	if (n == 1 || n == 4) return false;
	if (n == 2 || n == 3) return true;
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0)return false;
	return true;
}

int main()
{
	ll n;
	cin >> n;
	if (!isPrime(n - 4))cout << "4 " << n - 4;
	else
		if (!isPrime(n - 6)) cout << "6 " << n - 6;
		else
			cout << "8 " << n - 8;

	return 0;
}