#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int X,Y;
	cin >> X >> Y;
	int x=0,y=0,len=1,rot=0;
	while (1)
	{
		if (y==Y && X>=x && X<=x+len)
			break;		
		rot++;
		x += len;
		if (x==X && Y>=y && Y<=y+len)
			break;
		y += len;
		rot++;
		len++;
		if (y==Y && X<=x && X>=x-len)
			break;
		rot++;
		x -= len;
		if (x==X && Y<=y && Y>=y-len)
			break;
		y-=len;
		len++;
		rot++;
	}
	cout << rot << endl;
	return 0;
}