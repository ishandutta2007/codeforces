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
#include <fstream>
#include <cassert>
#include <deque>
#include <memory.h>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <stack>
#include <utility>
#include <complex>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
#define male -mod
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for (int i = (b-1); i>=(a); --i)
#define vec(a,n) vector<int> a(n)

int main()
{	
	int n;
	cin >> n;
	
	if (n % 2 == 0)
	{
		cout << n / 2 << endl;
		FOR(i, 0, n / 2)
			cout << "2 ";
	}
	else
	{
		cout << n / 2 << endl;
		cout << "3 ";
		FOR(i, 1, n / 2)
			cout << "2 ";
	}

	return 0;
}