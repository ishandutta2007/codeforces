#include<bits/stdc++.h>
using namespace std;
long long ans=1,a[5003][5003],x,y,z,b[5003];
int main(){
	a[0][0]=1;
	b[0]=1;
	for(int i=1;i<5003;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i>j)
				a[i][j]=a[i][j]+a[i-1][j];
			if(j)
				a[i][j]=a[i][j]+a[i-1][j-1];
			a[i][j]%=998244353;
		}
		b[i]=(b[i-1]*i)%998244353;
	}
	cin>>x>>y>>z;//  
	for(int i=0;i<3;i++){
		long long n,m,cur=0;
		if(i==0)n=x,m=y;
		if(i==1)n=x,m=z;
		if(i==2)n=y,m=z;
		for(int j=0;j<=min(n,m);j++)
			cur=(cur+(((a[n][j]*a[m][j])%998244353)*b[j])%998244353)%998244353;
		ans=(ans*cur)%998244353;
	}
	cout<<ans;
}