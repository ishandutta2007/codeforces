#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int flag;
int n;
int a[60][60];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	flag=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (a[i][j]<=1)continue;
			int judge=0;
			for(int k=1;k<=n;k++)
				for(int p=1;p<=n;p++)
					if (a[i][j]==a[i][k]+a[p][j])judge=1;
			if (!judge)flag=0;
		}
	if (!flag)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}