#include<iostream>
using namespace std;
int main(){
	int a[1000]={0},x,n,maxv=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[x-1]++;
	}
	x=0;
	for(int i=0;i<1000;i++)
		if(a[i]>0)
		{
			maxv=max(maxv,a[i]);
			x++;
		}
	cout<<maxv<<' '<<x;
}