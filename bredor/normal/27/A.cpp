//  228

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n,a[3005];
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	if(a[0]==1)
	{
		int i;
		for(i=0;i<n-1;++i)
		{
			if(a[i+1]-a[i]!=1)
			{
				cout<<a[i]+1<<endl;
				break;
			}
		}
		if(i>=n-1)
		{
			cout<<a[n-1]+1<<endl;
		}
		
	}
	else
	{
		cout<<"1"<<endl;
	}
	
	return 0;
}