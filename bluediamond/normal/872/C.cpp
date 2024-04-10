#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second


int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		if(n<=3) 
		{
			cout<<"-1\n";
			continue;
		}
		if(n%2==0)
		{
			cout<<n/4<<"\n";
			continue;	
		}
		if(n%4==1)
		{
			if(n>=9)
				cout<<1+(n-9)/4<<"\n";	
			else
				cout<<"-1\n";
			continue;		
		}
		if(n%4==3)
		{
			if(n>=15)
				cout<<2+(n-15)/4<<"\n";
			else
				cout<<"-1\n";
			continue;
		}
		cout<<"-1\n";
	}
	return 0;
}