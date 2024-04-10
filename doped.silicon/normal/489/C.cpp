#include <iostream>
using namespace std;

int main() {
	int m,n;
	cin>>m;
	cin>>n;
	if(n<=0&&m==1)
	{
		cout<<"0 0";
	}
	else if(n<=0||m*9<n)
	{
		cout<<"-1 -1"<<endl;
	}
	else
	{
		int a=n/9;
		int b=n%9;
		if(b==0)
		{
			if(a==m)
			{
				while(a>0)
				{
					cout<<"9";
					a--;
				}
			}
			else
			{
			    cout<<"1";
			    int k=0;
			    while(m-1-a-k>0)
			    {
			    	cout<<"0";
			    	k++;
			    }
			    cout<<"8";
			    while(a-1>0)
			    {
			    	cout<<"9";
			    	a--;
			    }
			}
		}
		else
		{
			if(a+1==m)
			{
				cout<<b;
				while(a>0)
				{
					cout<<"9";
					a--;
				}
			}
			else
			{
				cout<<"1";
			    int k=0;
			    while(m-2-n/9-k>0)
			    {
			    	cout<<"0";
			    	k++;
			    }
			    cout<<b-1;
			    while(a>0)
			    {
			    	cout<<"9";
			    	a--;
			    }
			}
		}
		a=n/9;
		cout<<" ";
		while(a>0)
		{
			cout<<"9";
			a--;
		}
		if(n/9!=m)
		cout<<b;
		int k=0;
		while(m-1-n/9-k>0)
		{
			cout<<"0";
			k++;
		}
	}
	return 0;
}