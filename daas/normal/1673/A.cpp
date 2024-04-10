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
int T;
char s[MAXS];
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),ansa=0,ansb=0;
		for(int i=1;i<=n;++i) ansa+=s[i]-'a'+1;
		if(n%2) ansb=min(s[1],s[n])-'a'+1,ansa-=ansb;
		if(ansa>ansb) printf("Alice %d\n",ansa-ansb);
		else printf("Bob %d\n",ansb-ansa);
	}
	return 0;
}
//ore no turn,draw!