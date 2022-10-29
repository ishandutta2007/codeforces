#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;

bool f(int h)
{
	int a=h/2,b=h/3,c=h/6;
	if(a>=n&&b>=m&&a+b-c>=n+m)return 1;
	return 0;
}

int main()
{
	cin>>n>>m;
	int low=-1,high=1000000000,mid;
	while(low+1<high)
	{
		mid=low+high>>1;
		if(f(mid))high=mid;
		else low=mid;
	}
	cout<<high<<endl;
	return 0;
}