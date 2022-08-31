#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
int n,m,i,j,s;
string st;
int main()
{
	cin>>st>>st;
	for (i=0;i<st.length();i++)
	{
		if (st[i]-'0')
		{
			s++;
		}
		else
		{
			cout<<s;
			s=0;
		}
	}
	cout<<s;
	return 0;
}