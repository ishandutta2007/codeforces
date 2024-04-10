#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		int cnt=a+b,big=a+d,small=c+b;
		if(cnt%2==0)
		{
			if(big&&small)
			{
				cout<<"Tidak Tidak Ya Ya\n";
			}
			else if(big)
			{
				cout<<"Tidak Tidak Tidak Ya\n";
			}
			else
			{
				cout<<"Tidak Tidak Ya Tidak\n";
			}
		}
		else
		{
			if(big&&small)
			{
				cout<<"Ya Ya Tidak Tidak\n";
			}
			else if(big)
			{
				cout<<"Ya Tidak Tidak Tidak\n";
			}
			else
			{
				cout<<"Tidak Ya Tidak Tidak\n";
			}
		}
	}
}