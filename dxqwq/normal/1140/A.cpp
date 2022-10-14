#include<bits/stdc++.h>
using namespace std;
int a[10003];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	int day=0,page=0,read=0;
	while(page!=n)
	{
		page++;
		read++;
		day++;
		for(int i=page; i<=read; i++) 
		{
			read=max(read,a[i]);
			page=read;
		}
	}
	cout<<day;
	return 0;
}