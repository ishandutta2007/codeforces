#include<bits/stdc++.h>
using namespace std;
int n,k,m,t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k>>m>>t;
	int total=n;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(!x)
		{
			if(k<=y)total=y;else total-=y;
			cout<<total<<' ';
			if(k<=y)
				cout<<k<<'\n';
			else
				cout<<k-y<<'\n',k-=y;
		}
		else{
			total++;
			cout<<total<<' ';
			if(y>k)
				cout<<k<<'\n';
			else
				cout<<k+1<<'\n',k++;
		}
	}
	return 0;
}