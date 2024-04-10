#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
	int i,ans,j,k,n,m;
	int a[19]={2,3,4,5,9,25,7,11,13,17,19,23,29,31,37,41,43,47,49};
	string s;
	for(i=j=0;i<19;i++)
	{
		cout<<a[i]<<"\n";
		fflush(stdout);
		cin>>s;
		if(s=="yes")j++;
	}
	if(j>1)cout<<"composite\n";
	else cout<<"prime\n";
}