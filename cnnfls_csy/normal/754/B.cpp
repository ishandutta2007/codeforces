#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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
using namespace std;
vector<pair<int,int>/**/> pos;
int n,m,i,j;
char mp[105][105];
int ok1,ok2,ok3;
int main()
{
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			cin>>mp[i][j];
			if (mp[i][j]=='x') pos.push_back(make_pair(i,j));
		}
	}
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (mp[i][j]=='o') continue;
			ok1=ok2=ok3=1;
			if (binary_search(pos.begin(),pos.end(),make_pair(i,j))) ok1=0;
			if (i>1&&i<4)
			{
				ok2=ok3=1;
				if (binary_search(pos.begin(),pos.end(),make_pair(i-1,j))) ok2=0;
				if (binary_search(pos.begin(),pos.end(),make_pair(i+1,j))) ok3=0;
				if (mp[i-1][j]=='o') ok2=1<<25;
				if (mp[i+1][j]=='o') ok3=1<<25;
				if (ok1+ok2+ok3<=1) {cout<<"YES";return 0;}
			}
			if (j>1&&j<4)
			{
				ok2=ok3=1;
				if (binary_search(pos.begin(),pos.end(),make_pair(i,j-1))) ok2=0;
				if (binary_search(pos.begin(),pos.end(),make_pair(i,j+1))) ok3=0;
				if (mp[i][j-1]=='o') ok2=1<<25;
				if (mp[i][j+1]=='o') ok3=1<<25;
				if (ok1+ok2+ok3<=1) {cout<<"YES";return 0;}
			}
			if (i>1&&i<4&&j>1&&j<4)
			{
				ok2=ok3=1;
				if (binary_search(pos.begin(),pos.end(),make_pair(i-1,j-1))) ok2=0;
				if (binary_search(pos.begin(),pos.end(),make_pair(i+1,j+1))) ok3=0;
				if (mp[i-1][j-1]=='o') ok2=1<<25;
				if (mp[i+1][j+1]=='o') ok3=1<<25;
				if (ok1+ok2+ok3<=1) {cout<<"YES";return 0;}
			}
			if (i>1&&i<4&&j>1&&j<4)
			{
				ok2=ok3=1;
				if (binary_search(pos.begin(),pos.end(),make_pair(i+1,j-1))) ok2=0;
				if (binary_search(pos.begin(),pos.end(),make_pair(i-1,j+1))) ok3=0;
				if (mp[i+1][j-1]=='o') ok2=1<<25;
				if (mp[i-1][j+1]=='o') ok3=1<<25;
				if (ok1+ok2+ok3<=1) {cout<<"YES";return 0;}
			}
		}
	}
	cout<<"NO";
	return 0;
}