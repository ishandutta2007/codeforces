
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#define ull unsigned long long
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
using namespace std;


int main() 
{

//	freopen("parenthr.in", "r", stdin);
//	freopen("parenthr.out", "w", stdout);
	ull n;
	cin >> n;
	if (n == 0)
	{
		cout << 1;
		return 0;

	}
	if (n % 4 == 1) cout << 8;
	if (n % 4 == 2) cout << 4;
	if (n % 4 == 3) cout << 2;
	if (n % 4 == 0) cout << 6;
}