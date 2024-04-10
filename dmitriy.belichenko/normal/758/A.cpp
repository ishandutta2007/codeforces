
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
long long b[100005];
using namespace std;


int main() 
{

//	freopen("parenthr.in", "r", stdin);
//	freopen("parenthr.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	ull cnt = 0;
	int mx = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mx = max(a[i], mx);
		
	}
	for (int i = 0; i < n; i++)
	{
		cnt += mx - a[i];
	}
	cout << cnt;
}