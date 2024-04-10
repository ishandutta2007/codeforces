#include<iostream>
using namespace std;
int a[5001][2];
int main()
{
	int x;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		a[i][0]=i;
		cin>>a[i][1];
		a[i][1]--;
	}
	if(x==2)
	{
		cout<<"NO";
		return 0;
	}
	for(int i=0;i<x;i++)
		if(a[a[a[i][1]][1]][1]==a[i][0])
		{
			cout<<"YES";
			return 0;
		}
	cout<<"NO";
}