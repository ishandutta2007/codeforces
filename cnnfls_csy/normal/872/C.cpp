#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,x;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		if (x<4||x==5||x==7||x==11)
		{
			cout<<-1<<endl;
		}
		else if (x%2==0)
		{
			cout<<x/4<<endl;
		}
		else
		{
			cout<<(x-9)/4+1<<endl;
		}
	}
	return 0;
}