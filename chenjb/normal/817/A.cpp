#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int x1,y1,x2,y2,x,y;
	cin>>x1>>y1>>x2>>y2>>x>>y;
	if (abs(x1-x2)%x!=0||abs(y1-y2)%y!=0)cout<<"NO"<<endl;
	else
	{
		int tmp1=abs(x1-x2)/x;
		int tmp2=abs(y1-y2)/y;
		if (abs(tmp1-tmp2)%2==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}