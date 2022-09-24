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
	int b[10000];
	for (int i = 0; i < 1000; i++)
		b[i] = 1;
	for (int i = 0; i < 1000; i++)
		for (int j = i + 1; j < 1000; j++)
			if (b[i] > b[j]) swap(b[i], b[j]);
	bool flag = 0;
	int n, m;
	char a[1005][1005];
	int secy = 0;
	int onex = -1;
	int oney = -1;
	int secx = 0;
	int l = 1005;
	int r = -1;
	cin >> n >> m;
	char c;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'X') 
			{
				if (onex == -1)
				{
					onex = j + 1;
					oney = i + 1;
					onex--;
					oney--;
				}
				secx = j + 1;
				secy = i + 1;
				secx--;
				secy--;
				l = min(l, j);
				r = max(r, j);
				
			}
		}
	if (l  < onex)
	{
		cout << "NO";
		flag = 1;
		return 0;
	}
	else
	if (r > secx)
	{
		flag = 1;
		cout << "NO";
		return 0;
	}
	else
	{
		for (int i = oney; i <= secy; i++)
			for (int j = onex; j < r + 1; j++)
			{
				if (!flag) 
				{
					if (l < onex)
					{
						cout << "NO";
						flag = 1;
						return 0;
					}
					else
						if (r > secx)
						{
							flag = 1;
							cout << "NO";
							return 0;
						}
				}
				if (a[i][j] != 'X')
				{
					cout << "NO";
					return 0;
				}
			}
		if( !flag ) cout << "YES";
	}
}