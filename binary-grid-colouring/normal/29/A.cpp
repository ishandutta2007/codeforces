#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]==a[i]+b[i] && a[i]==a[j]+b[j])
			{
				puts("YES");exit(0);
			}
		}
	}
	puts("NO");
	return 0;
}