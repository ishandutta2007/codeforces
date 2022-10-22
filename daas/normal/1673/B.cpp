#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
const int MAXS=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,flag,pd[30];
char s[MAXS];
void check(int a,int b)
{
	int las=-1;
	for(int i=1;i<=n;++i) if(s[i]-'a'==a || s[i]-'a'==b)
	{
		if(las==-1) las=(s[i]-'a'==a);
		else if(las==1)
		{
			if(s[i]-'a'==a) {flag=1;return;}
			las=0;
		}
		else
		{
			if(s[i]-'a'==b) {flag=1;return;}
			las=1;
		}
	}
}
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(pd,0,sizeof(pd));
		for(int i=1;i<=n;++i) pd[s[i]-'a']=1;
		flag=0;
		for(int i=0;i<26;++i) if(pd[i])
			for(int j=i+1;j<26;++j) if(pd[j])
				check(i,j);
		puts(flag?"NO":"YES");
	}
	return 0;
}
//ore no turn,draw!