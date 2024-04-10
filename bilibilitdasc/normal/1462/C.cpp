#include <iostream>
using namespace std;
void mx(int x)
{
	int ans=0,i;
	for(i=9;i>0;i--)
	{
		x-=i;
		if(x<=0)
		break;
	}
	x+=(i++);
	cout<<x;
	for(int j=i;j<10;j++)
	cout<<j;
	cout<<'\n';
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int u;
		cin>>u;
		if(u>45)
		cout<<"-1\n";
		else
		mx(u);
	}
	return 0;
}