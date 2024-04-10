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
int n,m,s,v0,v1,l,a;
string st;
int main()
{
	cin>>n>>v0>>v1>>a>>l;
	while (n>0)
	{
		n-=v0;
		if (s) n+=l;
		v0=min(v1,v0+a);
		s++;
	}
	cout<<s;
	return 0;
}