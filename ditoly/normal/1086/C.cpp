#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
const int MN=1e6;
char s[MN+5],a[MN+5],b[MN+5],t[128],u[128];
int main()
{
	int T=read(),n,k,x,i,j,A,B;
	while(T--)
	{
		k=read();
		scanf("%s%s%s",s,a,b);n=strlen(s);
		for(x=0;x<2;++x)
		{
			memset(t,0,sizeof(t));
			memset(u,0,sizeof(u));
			for(i=0,A=B=1;i<n;++i)
			{
				if(t[s[i]])
				{
					if(A)
					{
						if(t[s[i]]<a[i])break;
						if(t[s[i]]>a[i])A=0;
					}
					if(B)
					{
						if(t[s[i]]>b[i])break;
						if(t[s[i]]<b[i])B=0;
					}
				}
				else
				{
					if(A&&B)
					{
						if(a[i]==b[i])
						{
							if(u[a[i]])break;
							t[s[i]]=a[i];u[a[i]]=1;
							continue;
						}
						for(j=a[i];++j<b[i];)if(!u[j]){t[s[i]]=j;u[j]=1;break;}
						if(t[s[i]]){A=B=0;continue;}
						if(x)
						{
							if(u[a[i]])break;
							t[s[i]]=a[i];u[a[i]]=1;B=0;
						}
						else
						{
							if(u[b[i]])break;
							t[s[i]]=b[i];u[b[i]]=1;A=0;
						}
					}
					else if(A)
					{
						for(j=a[i];++j<k+'a';)if(!u[j]){t[s[i]]=j;u[j]=1;break;}
						if(t[s[i]]){A=0;continue;}
						if(u[a[i]])break;
						t[s[i]]=a[i];u[a[i]]=1;
					}
					else if(B)
					{
						for(j=b[i];--j>='a';)if(!u[j]){t[s[i]]=j;u[j]=1;break;}
						if(t[s[i]]){B=0;continue;}
						if(u[b[i]])break;
						t[s[i]]=b[i];u[b[i]]=1;
					}
				}
			}
			if(i<n)continue;
			for(i=j='a';i<k+'a';++i)if(!t[i]){while(u[j])++j;t[i]=j;u[j]=1;}
			puts("YES");
			for(i='a';i<k+'a';++i)putchar(t[i]);puts("");
			break;
		}
		if(x>1)puts("NO");
	}
}