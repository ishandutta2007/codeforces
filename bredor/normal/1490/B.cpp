#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,cnt=0,c[3]={0};
	cin>>n;
	vector<int> a(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		c[a[i]%3]++;
	}
	for(i=0;i<4;i++)
		if(c[i%3]>n/3)
		{
			cnt+=c[i%3]-n/3;
			c[(i+1)%3]+=c[i%3]-n/3;
			c[i%3]=n/3;
		}
	cout<<cnt<<endl;
}
}