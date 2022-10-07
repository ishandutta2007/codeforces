#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n;
char l[N],r[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",l);
	scanf("%s",r);
	if(l[0]!=r[0])
		for(int i=0;i<n;++i)
			putchar('1');
	else
	{
		if(r[n-1]=='0')
		{
			int i;
			for(i=0;i<n;++i)
				if(l[i]!=r[i])
					break;
			if(i!=n)
			{
				i=n-1;
				while(l[i]=='1')
				{
					l[i]='0';
					--i;
				}
				l[i]='1';
				for(i=0;i<n;++i)
					if(l[i]!=r[i])
						break;
				if(i!=n)
					r[n-1]='1';
			}
			printf("%s",r);
		}
		else
			printf("%s",r);
	}
}