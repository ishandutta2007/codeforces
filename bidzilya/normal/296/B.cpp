#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int module = 1e9+7;

int n;
string s1,s2;

int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	cin >> n;
	cin.ignore();
	getline(cin, s1);
	getline(cin, s2);
	int all=1;
	for (int i=0; i<n; i++)
	{
		if (s1[i]=='?')all=(10LL*all)%module;
		if (s2[i]=='?')all=(10LL*all)%module;
	}
	int big=1;
	int bbig=1;
	for (int i=0; i<n; i++)
		if (s1[i]=='?' && s2[i]=='?')
			big = (55LL*big)%module;
		else
		if (s1[i]=='?')
			big = (1LL*big*(10-(s2[i]-'0')))%module;
		else
		if (s2[i]=='?')
			big = (1LL*big*(1+s1[i]-'0'))%module;
		else
		if (s1[i]<s2[i])
			bbig = 0;
	int small=1;
	int bsmall=1;
	int sum=1;
	for (int i=0; i<n; i++)
		if (s1[i]=='?' && s2[i]=='?')
		{
			small = (55LL*small)%module;
			sum = (10LL*sum)%module;
		}else
		if (s1[i]=='?')
			small = (1LL*small*(s2[i]-'0'+1))%module;
		else
		if (s2[i]=='?')
			small = (1LL*small*(10-(s1[i]-'0')))%module;
		else
		if (s1[i]>s2[i])
			bsmall=0;
	if (bsmall)
	{
		all -= small;
		if (all < 0)
			all += module;
	}
	if (bbig)
	{
		all -= big;
		if (all < 0)
			all += module;
		if (bbig && bsmall)
		{
			all += sum;
			all %= module;
		}
	}	
	cout << all << endl;
	return 0;
}