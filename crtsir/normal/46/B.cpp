#include<iostream>
using namespace std;
int main()
{
	int a[5],n;
	for(int i=0;i<5;i++)
		cin>>a[i];
	cin>>n;
	string s;
	int x[n];
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s=="XXL")x[i]=4;
		if(s=="XL")x[i]=3;
		if(s=="L")x[i]=2;
		if(s=="M")x[i]=1;
		if(s=="S")x[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int l=0,real,r=0;//x(3 4 1),a(1 0 2 0 1)
		while(x[i+l]>-1)
		{
			if(a[x[i]+l]>0)
				break;
			else
				l--;	
		}
		if(x[i]+l<0)
			l=-7;
		while(x[i]+r<5)
		{
			if(a[x[i]+r]>0)
				break;
			else
				r++;
		}
		if(x[i]+r>4)
			r=7;
		if(r<=-l)
			real=x[i]+r;
		else
			real=x[i]+l;
		a[real]--;
		if(real==0)cout<<"S"<<endl;
		if(real==1)cout<<"M"<<endl;
		if(real==2)cout<<"L"<<endl;
		if(real==3)cout<<"XL"<<endl;
		if(real==4)cout<<"XXL"<<endl;
	}
}