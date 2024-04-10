#include<iostream>
using namespace std;
int main()
{
	int x=0,n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		cin>>c;
		if (c==45) x--;
		else x++;
		cin>>c;
		//cin>>c;
	}
	cout<<x;
	return 0;
}