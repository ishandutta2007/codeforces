#include<bits/stdc++.h>
using namespace std;
int a[2006];
char c[2006][2006];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
		for(int j=0;j<m;j++)
			a[j]+=c[i][j]=='1';
	}
	for(int i=0;i<n;i++)
	{
		bool ok=true;
		for(int j=0;j<m&&ok;j++)
			ok=a[j]-(c[i][j]=='1');
		if(ok){cout<<"YES";return 0;}
	}
	cout<<"NO";
}