#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,pd[200010];
char s[200010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s",s+1);
		int num=0;
		for(int i=1;i<=n;++i) num=(num+s[i]-'0')%2;
		if(num) {puts("NO");continue;}
		for(int i=1;i<=n;++i) num+=s[i]-'0';
		if(num<2) {puts("NO");continue;}
		int x=1; while(s[x]=='0') ++x;
		int y=x+1; while(s[y]=='0') ++y;
		if(x==1 && y==n)
		{
			puts("YES");
			for(int i=1;i<n;++i) printf("%d %d\n",i,i+1);
			continue;
		}
		int suf=(y==n?1:y+1);
		puts("YES");
		for(int i=x+2;i<=y;++i) printf("%d %d\n",i,i-1);
		printf("%d %d\n",x+1,suf);
		for(int i=1;i<=n;++i) if(i!=suf && !(x<i && i<=y))
		{
			int p=(i==1?n:i-1);
			if(s[p]=='1') printf("%d %d\n",i,suf);
			else printf("%d %d\n",i,p);
		}
	}
	return 0;
}
//ore no turn,draw!