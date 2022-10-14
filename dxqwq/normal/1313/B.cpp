#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<min(a,max(b+c-a+1,1))<<' '<<min(a,b+c-1)<<endl;
	}
	return 0;
}