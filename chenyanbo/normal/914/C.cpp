#include<bits/stdc++.h>
#define MO 1000000007
//ab  mi ma //abs fabs //(-(a))   ab(a)     >0?  :
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

char s[1009];
int ss,p,o,k,a[1009],l,ans,f[1009],c[1009][1009];//memset  memcpy    xd   dx xd

inline int su(int p)
{
	int s=0;
	while(p)
	{
		s+=p&1;
		p/=2;
	}
	return s;
}

inline int che(int p)
{
	if(p>l)return 0;
	int uu=p,ans=0;
	for(int i=1; i<=l; ++i)
	{
		if(a[i])
		{
//			for(int j=0; j<i; ++j)
			ans=(ans+c[l-i][uu])%MO; 
			--uu;
			if(uu<0)break;
		}
		
	}
	return ans%MO;
}//no %= ()%=

int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);//l-i+1
	for(int i=1; i<=l; ++i)a[i]=s[i]-48;
	for(int i=1; i<=l; ++i)ss+=(a[i]>0);//namespace ss //0 //0
	k=read(); //()  ()  ll -4
	if(k>5)
	{
		puts("0");
		return 0;
	}
	if(l==1)
	{
		if(!k)puts("1");
		else puts("0");
		return 0;
	}
	
	if(!k)
	{
		puts("1");
		return 0;
	}
	
	if(k==1)
	{
		printf("%d\n",l-1);
		exit(0);
	}
	
	c[0][0]=1;
	for(int i=1; i<=1000; ++i)
	{
		c[i][0]=1;
		for(int j=1; j<=i; ++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%MO;
	}
	
	for(int i=1; i<=1000; ++i)
	{
		p=i; o=0;
		while (p!=1)
		{
			++o;
			p=su(p);
		}
		if(o==k-1)f[i]=1;
	}
	for(int i=1; i<=1000; ++i)if(f[i])ans=(ans+che(i))%MO;
	if(f[ss])ans=(ans+1)%MO;
	printf("%d\n",ans);
}