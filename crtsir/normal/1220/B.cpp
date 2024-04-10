#include<bits/stdc++.h>
using namespace std;
long long a[1003],n,c[1003][1003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&c[i][j]);
	for(int i=0;i<n;i++)
		if(i==0)
			a[i]=sqrt(c[i][1]*c[i][2]/c[1][2]);
		else if(i==1)
			a[i]=sqrt(c[i][0]*c[i][2]/c[0][2]);
		else
			a[i]=sqrt(c[i][0]*c[i][1]/c[0][1]);
	for(int i=0;i<n;i++)cout<<a[i]<<' ';
}