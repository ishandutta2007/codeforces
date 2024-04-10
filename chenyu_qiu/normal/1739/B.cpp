#include<bits/stdc++.h>
using namespace std;
int t,n,a[101],flag;
int main()
{
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		cin>>n;
		flag=1;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=2;i<=n;i++)
		{
			if(a[i-1]>=a[i]&&a[i]!=0)
			{
				flag=0;
				break;
			}
			else
				a[i]+=a[i-1];
		}
		if(!flag)	cout<<-1;
		else
			for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}