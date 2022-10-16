#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	cin>>T;
	while(T--)
	{
		int n,x;
		cin>>n;
		vector<int>a,b;
		for(int i=0;i<2*n;i++)
		{
			cin>>x;
			if(x%2)a.push_back(i+1);
			else b.push_back(i+1);
		}
		int cnt=0;
		for(int i=0;i+1<a.size()&&cnt<n-1;i+=2,cnt++)cout<<a[i]<<' '<<a[i+1]<<endl;
		if(b.size()>1)for(int i=0;i<n-1-a.size()/2;i++)cout<<b[i*2]<<' '<<b[i*2+1]<<endl;
	}
}