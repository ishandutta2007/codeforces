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
map<string,int> used;
string st;
int n,i,j;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st;
		if (!used.count(st)) cout<<"OK"<<endl;
			else cout<<st<<used[st]<<endl;
		used[st]++;
	} 
	return 0;
}