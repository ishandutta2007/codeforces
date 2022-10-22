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
int n,las[26],top,z[30];
char s[1010];
void solve(int x)
{
	top=0;
	for(int i=0;i<26;++i) if(las[i]) z[++top]=las[i];
	sort(z+1,z+top+1);
	int l=1,r=top,pos=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		printf("? 2 %d %d\n",z[mid],x);
		fflush(stdout);
		int val=read();
		if(val==top-mid+1) pos=z[mid],l=mid+1;
		else r=mid-1;
	}
	if(pos==-1)
	{
		printf("? 1 %d\n",x);
		fflush(stdout);
		scanf("%c",&s[x]);
	}
	else s[x]=s[pos];
}
int main()
{
	n=read();
	printf("? 1 %d\n",1);
	fflush(stdout);
	scanf("%c",&s[1]);
	las[s[1]-'a']=1;
	for(int i=2;i<=n;++i)
	{
		solve(i);
		las[s[i]-'a']=i;
	}
	printf("! %s\n",s+1);
	fflush(stdout);
	return 0;
}
//ore no turn,draw!