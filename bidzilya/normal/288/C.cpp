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
using namespace std;

int n;
vector<int> us,pos;
long long sum=0;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n;
	us.resize(n+1);
	pos.resize(n+1);
	for (int i=n; i>=0; i--)
		if (!us[i])
		{
			int j=i;
			int x=0;
			int st=0;
			while (j)
			{
				if (j%2==0)
					x += (1<<st);
				st++;
				j/=2;
			}
			us[i]=us[x]=1;
			pos[i]=x;
			pos[x]=i;
			sum += (x^i);
			sum += (x^i);
		}
	cout << sum << endl;
	for (int i=0; i<=n; i++)
		cout << pos[i] << " ";
	cout << endl;

	return 0;
}