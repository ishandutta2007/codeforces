#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>
 
const int N=400010;
const int inf=0x3f3f3f3f;
 
using namespace std;
 
int d,len;
char s[N],t[N];
unsigned long long e[N],a[N],b[N];
 
bool check(int x,int y)
{
	if(x<y-1) return 1;
	unsigned long long aa,bb;
	aa=a[x+1]-a[x-y+1];
	bb=b[x+1]-b[x-y+1]*e[y];
	bb*=e[x-y+1];
	//cout<<x<<" "<<y<<endl;
	//for(int i=0;i<=x;i++)
		//cout<<t[i];
	//cout<<endl;
	//for(int i=0;i<=x;i++)
		//cout<<a[i]<<" ";cout<<endl;
	//for(int i=0;i<=x;i++)
		//cout<<b[i]<<" ";cout<<endl;
	//cout<<aa<<" "<<bb<<endl;
	return aa!=bb;
}
 
bool dfs(int x,bool f)
{
	//cout<<x<<" "<<f<<endl;
	if(x==len) return 1;
	for(t[x]=(f?'a':s[x]);t[x]<='z';t[x]++)
	{
		a[x+1]=a[x]+t[x]*e[x],b[x+1]=b[x]*127+t[x];
		if(check(x,d) && check(x,d+1))
		{
			if((t[x]>s[x]) && dfs(x+1,1)) return 1;
			else if((t[x]<=s[x]) && dfs(x+1,f)) return 1;
		}
	}
	return 0;
}
 
int main()
{
	scanf("%d%s",&d,s);
	bool f=0;
	len=strlen(s);
	int id=len;
	e[0]=1;
	for(int i=1;i<=len;i++) e[i]=e[i-1]*127;
	for(int i=len-1;(i>=0) && (s[i]=='z');i--) id=i,s[i]='a';
	if(id==0)
	{
		puts("Impossible");
		return 0;
	}
	s[id-1]++;
	t[len]=0;
	if(dfs(0,0)) puts(t);
	else puts("Impossible");
	return 0;
}