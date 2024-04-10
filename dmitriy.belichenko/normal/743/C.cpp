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
	int n;
	cin >> n;
	/*int a[10000];
	int u = 0;
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			n = n / i;
			a[u] = i;
			a[u + 1] = n;
			u = u + 2;
		}
	
	else cout << -1;
	//for (int i = 0; i < u; i++) cout << a[i] << " ";
	*/
	if (n * (n + 1) > 1000000000 || n == 1) cout << -1;
	else cout << n << " " << n + 1 << " " << n*(n + 1);
}