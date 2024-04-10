#include <stdio.h>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
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
#include <string>
#define ull long long
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
typedef long long ll;

vector<int> cap;
vector<int> a[1105];
int p[1105];
int q[1105];
int V = 0;
int SV = 0;
int SE = 0;
bool used[1005];
int vert(int a)
{
	return ((a*(a - 1)) / 2);
}

int main()
{
	int n;

	cin >> n;
	int ans = 1;
	int b = n + 1;
	for (int a = 1; a < n; a++)
	{
		if (n % a == 0) 
		{
			int k = a - n/a;
			int p = ans - n / ans;
			if ( abs( k) < abs(p)) ans = a;
		}
	}
	b = max(ans, n / ans);
	ans = min(ans, n / ans);
	cout << ans << " " << b;
}