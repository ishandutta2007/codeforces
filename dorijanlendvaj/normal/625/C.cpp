#include <bits/stdc++.h>

using namespace std;

int n,n2,n3,k,r;
int mat[501][501];

int main()
{
	cin>>n>>k;
	n2=n*n;
	n3=0;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<k-1;++j)
		{
			if (j==k-1) r+=n3+1;
			mat[i][j]=n3+1;
			++n3;
		}
		n2-=(n-k+1);
		for (int j=k-1;j<n;++j)
		{
			if (j==k-1) r+=n2+1;
			++n2;
			mat[i][j]=n2;
		}
		n2-=(n-k+1);
	}
	cout<<r<<endl;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			cout<<mat[i][j]<<' ';
		}
		cout<<endl;
	}
}