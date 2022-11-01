#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int main()
{
	int n,a,b;
	cin>>a>>b>>n;
	for(long double i = -1000;i<=1000;i++)
	{
		if(a*pow(i,n)==b)
		{
			cout<<i<<endl;
			exit(0);
		}
	}
	cout<<"No solution"<<endl;
	return 0;
}