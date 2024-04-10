#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin>>n;
	string a1,b1;
	cin>>a1>>b1;
	vector<int> c,b,a,d;
	for(int i=0;i<n;i++)
	{
		if(a1[i]=='0')
		{
			if(b1[i]=='0')a.push_back(i);
			else b.push_back(i);
		}
		else{
			if(b1[i]=='0')c.push_back(i);
			else d.push_back(i);
		}
	}
	for(int i=0;i<=d.size();i++)
	{
		for(int j=0;j<=c.size();j++)
		{
			int t=b.size() + d.size();
			int b2=t-j-2*i;
			int a2=n/2-b2-i-j;
			if(a2<=a.size() && b2<=b.size() && a2>=0 && b2>=0)
			{
				for(int p=0;p<i;p++)
				cout<<d[p]+1<<" ";
				for(int p=0;p<j;p++)
				cout<<c[p]+1<<" ";
				for(int p=0;p<b2;p++)
				cout<<b[p]+1<<" ";
				for(int p=0;p<a2;p++)
				cout<<a[p]+1<<" ";
				return 0;
			}
		}
	}
	cout<<"-1";
	return 0;
}