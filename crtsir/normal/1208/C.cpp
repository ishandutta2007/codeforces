#include<bits/stdc++.h>
using namespace std;
int a[1003][1003],n,s;
int main(){
	cin>>n;
	for(int i=0;i<n/2;i++)
		for(int j=0;j<n/2;j++)
			a[i][j]=s++,
			a[i][j+n/2]=s++,
			a[i+n/2][j]=s++,
			a[i+n/2][j+n/2]=s++;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
}