#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

int n;
string s;

int main()
{
	ios_base::sync_with_stdio(0);

//	ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	int t;
	ll sx,sy,ex,ey;
	cin >> t >> sx >> sy >> ex >> ey;
	cin.ignore();
	string s;
	getline(cin, s);
	ll dist = abs(sx-ex)+abs(sy-ey);
	for (int i=0; i<t; i++)
	{
		ll nx=sx,ny=sy;

		if (s[i]=='S')
			ny--;
		else
		if (s[i]=='N')
			ny++;
		else
		if (s[i]=='E')
			nx++;
		else
			nx--;
		ll ndist = abs(nx-ex)+abs(ny-ey);
		if (ndist < dist) 
		{
			dist = ndist;
			sx = nx;
			sy = ny;
		}
		if (dist == 0)
		{
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}