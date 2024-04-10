#include <iostream>
#include <fstream>
using namespace std;
int mo(int x)
{
	if(x<0) return -x;
	else return x;
}
int main()
{
	int n, l=0, r=0;
	cin>>n;
	int ar[n][2], be, an=0;
	for(int a=0; a<n; a++)
	{
		cin>>ar[a][0]>>ar[a][1];
		l+=ar[a][0], r+=ar[a][1];
	}
	be=mo(l-r);
	for(int a=0; a<n; a++)
	{
		if(mo((l-ar[a][0]+ar[a][1])-(r-ar[a][1]+ar[a][0]))>be)
		{
			be=mo((l-ar[a][0]+ar[a][1])-(r-ar[a][1]+ar[a][0])), an=a+1;
		}
	}
	cout<<an;
}