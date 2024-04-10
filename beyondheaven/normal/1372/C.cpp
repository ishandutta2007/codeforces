#include<bits/stdc++.h>
#define MaxN 200123
int a[MaxN];
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		scanf("%d",a+i);
		bool flag1=true;
		for(int i=1;i<=n;++i)
		if(a[i]!=i)flag1=false;
		if(flag1){puts("0");continue;}
		bool flag2=true;
		int l,r;
		for(l=1;a[l]==l;++l);
		for(r=n;a[r]==r;--r);
		for(int i=l;i<=r;++i)
		if(a[i]==i)flag2=false;
		if(flag2){puts("1");continue;}
		puts("2");
	}
	return 0;
}