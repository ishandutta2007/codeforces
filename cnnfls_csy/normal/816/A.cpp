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
#define push_back pb
#define make_pair mr
using namespace std;
int n,m,i,j,ans;
string st;
bool check(int x,int y)
{
	if (x%10*10+x/10==y) return 1;
	return 0; 
}
int main()
{
	scanf("%d:%d",&n,&m);
	while (!check(n,m))
	{
		ans++;
		m++;
		if (m>59)
		{
			m=0;n++;
		 } 
		 if (n>23)
		 {
		 	n=0;
		  } 
	}
	cout<<ans;
	return 0;
}