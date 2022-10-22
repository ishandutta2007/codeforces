#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[100005];
int main()
{
	cin>>n;
	int i;
	for(i=0;i<n;i++) cin>>a[i];
	int mn=2147483647,mn2=2147483647;
	for(i=0;i<n;i++)
	    if(a[i]<mn) mn=a[i];
	int cnt=0;
	bool d=0;
	for(i=0;i<n;i++)
	{
	    if(d==1) cnt++;
		if(a[i]==mn)
		{
			if(cnt<mn2&&cnt!=0) mn2=cnt;
			cnt=0;
		}
		
		if(a[i]==mn) d=1;
	}
	
	cout<<mn2;
	return 0;
}