#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2520;
int n,m,k,t,i,h[15],j;
char c[100005];
int main()
{
	scanf("%d",&n);
	scanf("%s",c+1);
	for(i=1;i<=n;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
			h[c[i]-'0']=0;
		if(c[i]=='L')
			for(j=0;j<10;j++)
				if(h[j]==0)
				{
					h[j]=1;
					break;
				}
		if(c[i]=='R')
			for(j=9;j>=0;j--)
				if(h[j]==0)
				{
					h[j]=1;
					break;
				}
	}
	for(i=0;i<=9;i++)
		printf("%d",h[i]);
}