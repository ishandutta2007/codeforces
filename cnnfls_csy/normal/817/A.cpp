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
int x,xx,y,yy,dx,dy;
int main()
{
	cin>>x>>y>>xx>>yy>>dx>>dy;
	if (abs(xx-x)%dx) {cout<<"NO";return 0;} 
	if (abs(yy-y)%dy) {cout<<"NO";return 0;} 
	//cerr<<abs((abs(x-xx)/dx)-(abs(y-yy)/dy))<<endl;
	if (!(abs((abs(x-xx)/dx)-(abs(y-yy)/dy))%2)) cout<<"YES";
	else cout<<"NO";
	return 0;
}