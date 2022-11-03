#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;	

char a[1111111];
vector<int> aa,ast;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> (a+10);
	int st=0,cnt=0;
	for (int i=strlen(a+10)+9; i>=0; i--)
	{
		if (a[i]=='1')
			cnt++;
		else
		{
			if (cnt==1)
			{
				aa.push_back(+2);
				ast.push_back(st-1);
				cnt=0;
			}else
			if (cnt>1)
			{
				aa.push_back(-2);
				ast.push_back(st-cnt);
				cnt=1;
			}
		}
		st++;
	}
	cout << aa.size() << endl;
	for (int i=0; i<aa.size(); i++)
	{
		if (aa[i]>0)
			cout << '+';
		cout << aa[i] << '^' << ast[i] << endl;
	}
	return 0;
}