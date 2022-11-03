#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

typedef long long ll;

int a[4][4];

int main()
{
	//ifstream cin("input.txt");
//	ofstream cout("output.txt");
	for (int i=0; i<4; i++)
	{
		string s;
		getline(cin,s);
		for (int j=0; j<4; j++)
			a[i][j]=(s[j]=='#');
	}
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
		{
			int k=a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i][j+1];
			if (k!=2)
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	cout << "NO" << endl;	
	return 0;
}