#include<stdio.h>
#include<string.h>
int n,l[300001],r[300001],sl[300001],sr[300001],el[300001],er[300001],x,y,maxi;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d %d",&l[i],&r[i]);
	sr[0]=0x7fffffff;
	er[n+1]=0x7fffffff;
	for(int i=1;i<n;++i)
	{
		if(l[i]>sl[i-1])sl[i]=l[i];
		else sl[i]=sl[i-1];	
		if(r[i]<sr[i-1])sr[i]=r[i];
		else sr[i]=sr[i-1];	
	}
	for(int i=n;i>1;--i)
	{
		if(l[i]>el[i+1])el[i]=l[i];
		else el[i]=el[i+1];	
		if(r[i]<er[i+1])er[i]=r[i];
		else er[i]=er[i+1];	
	}
	for(int i=1;i<=n;++i)
	{
		if(sl[i-1]>el[i+1])x=sl[i-1];
		else x=el[i+1];
		if(sr[i-1]<er[i+1])y=sr[i-1];
		else y=er[i+1];	
		if(y-x>maxi)maxi=y-x;
	}
	printf("%d",maxi);
	return 0;
}