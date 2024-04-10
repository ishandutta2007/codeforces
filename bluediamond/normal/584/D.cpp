#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int x)
{
	if(x<=1)
		return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}


void Slove(int n)
{
	if(IsPrime(n))
	{
		cout<<"1\n"<<n<<"\n";
		return;
	}
	if(IsPrime(n-2))
	{
		cout<<"2\n"<<2<<" "<<n-2<<"\n";
		return;
	}
	if(IsPrime(n-4))
	{
		cout<<"3\n"<<2<<" "<<2<<" "<<n-4<<"\n";
		return;
	}
	int p=2;
	while(1)
	{
		while(IsPrime(p)==0)
			p++;
		if(IsPrime(n-2*p)==1)
		{
			cout<<"3\n";
			cout<<p<<" "<<p<<" "<<n-2*p<<"\n";
			return;
		}
		p++;
	}
	cout<<"-1\n";
}

int main()
{
    int n;
    cin>>n;
    Slove(n);
	return 0;
}