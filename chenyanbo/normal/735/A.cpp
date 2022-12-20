#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int y[101],t,g,n,k,a[101];
char s[103]; //102 101 //100    //102
int main()
{
	n=read(); k=read();
	scanf("%s",s+1);//".."  ' ' 
	int l=strlen(s+1); //s
	for(int i=1; i<=l; ++i)
	{
		if(s[i]=='#')a[i]=1;
		if(s[i]=='G')g=i;
		if(s[i]=='T')t=i;
	}
	y[g]=1;
	for(int i=1; i<=1000; ++i)
	{
		
		//int i=i //+1
		for(int j=1; j<=n; j++)
		{
			if(y[j] && j>k && !a[j-k])y[j-k]=1;
			if(y[j] && j<=n-k && !a[j+k])y[j+k]=1;  //!
		}
	}
	if(y[t])puts("YES");else puts("NO");
}