#include<cstdio>
#include<cstring>
#define MN 100000
char s[MN+5];
int main()
{
	int n,i,f=0,f1=0,f2=0,ans=-1,p,pf1,pf2;
	scanf("%s",s+1);n=strlen(s+1);
	for(i=n;i;--i)
	{
		f=(f+(s[i]-='0'))%3;
		if(s[i])
		{
			if(!f&&(ans<0||i<=ans))ans=i-1,p=i,pf1=pf2=0;
			if(f==1&&f1&&(ans<0||i<ans))ans=p=i,pf1=1,pf2=0;
			if(f==1&&f2>1&&(ans<0||i+1<ans))ans=i+1,p=i,pf1=0,pf2=2;
			if(f==2&&f2&&(ans<0||i<ans))ans=p=i,pf1=0,pf2=1;
			if(f==2&&f1>1&&(ans<0||i+1<ans))ans=i+1,p=i,pf1=2,pf2=0;
		}
		else if(ans<0)ans=-2;
		if(s[i]%3==1)++f1;
		if(s[i]%3==2)++f2;
	}
	if(ans<-1)return 0*puts("0");
	if(ans<0)return 0*puts("-1");
	for(printf("%d",s[i=p]);++i<=n;)
		if(s[i]%3==1&&pf1)--pf1;
		else if(s[i]%3==2&&pf2)--pf2;
		else printf("%d",s[i]);
}