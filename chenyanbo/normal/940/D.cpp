#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0,f=1; char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-')f=-1;
	    c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return f*ret;
}

int a[110005],l,r,n;
char s[110005];

int main()
{
	n=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	scanf("%s",s+1);
	
	l=-1000000000; r=1000000000;
	
	for(int i=5; i<=n; ++i)
	{
		if(s[i]=='0')
		{
			if(s[i-1]==s[i-2]&&s[i-2]==s[i-3]&&s[i-3]==s[i-4])
			{
				if(s[i-1]=='1'){
					
					for(int j=i-4; j<=i; ++j)
					r=min(r,a[j]-1);
				}
				//else
//				{
					
				//}
			}
		}
		else
		{
			if(s[i-1]==s[i-2]&&s[i-2]==s[i-3]&&s[i-3]==s[i-4])
			{
				if(s[i-1]=='0'){
					
					for(int j=i-4; j<=i; ++j)
					l=max(l,a[j]+1);
				}
			}
		}
	}
	printf("%d %d\n",l,r);///-1 \n///
}