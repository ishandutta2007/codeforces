#include <bits/stdc++.h>

using namespace std;

bool prime(int a)
{
	if(a<=1)
		return 0;
	for(int i=2;i*i<=a;i++)
		if(a%i==0)
			return 0;
	return 1;
}

int n,m;

int main() 
{
	cin>>n>>m;	
	int rest=n-2;
	int last=1;
	while(prime(rest+last)==0)
		last++;
	int sum=rest+last;
	cout<<sum<<" "<<sum<<"\n";
	for(int i=1;i+1<n;i++)
		cout<<i<<" "<<i+1<<" 1\n";
	cout<<n-1<<" "<<n<<" "<<last<<"\n";
	int need=m-(n-1);
	int i=1,j=1;
	while(need--)
	{
		while(abs(j-i)<=1)
		{
			j++;
			if(j>n)
			{
				i++;
				j=i;		
			}
		}
		cout<<i<<" "<<j<<" 1000000000\n";
		j++;
		if(j>n)
		{
			i++;
			j=i;			
		}
	}	
	return 0;
}