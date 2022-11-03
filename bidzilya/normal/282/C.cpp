#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-8;
const double PI = acos(-1.0);

string s1,s2;

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	getline(cin,s1);
	getline(cin,s2);
	if (s1.length()!=s2.length())
	{
		cout << "NO" << endl;
		return 0;
	}
	int c1=0,c2=0;
	for (int i=0; i<s1.length(); i++)
	{
		if (s1[i]=='1')c1++;
		if (s2[i]=='1')c2++;
	}
	if (c1==0)
	{
		if (c2!=0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		return 0;
	}
	if (c2==0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}