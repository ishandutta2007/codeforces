#include<bits/stdc++.h>
using namespace std;
int b,k,a[100003];
int main()
{
	bool tot=true,now=false;//falsetrue 
	scanf("%d%d",&b,&k);
	for(int i=1; i<=k; i++) scanf("%d",&a[i]);
	bool evenb=false,nowa=false;
	if(b%2==0) evenb=true;
	for(int i=1; i<=k; i++)
	{
		if(i==k) evenb=false;
		if(a[i]%2==0) nowa=true;
		else nowa=false;
		now=nowa || evenb;
		if(!now) tot=!tot;
	}
	if(tot) cout<<"even";
	else cout<<"odd";
	return 0;
}