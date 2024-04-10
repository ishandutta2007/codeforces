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
int n,ans=1000;
unsigned long long goal,x;
int check(unsigned long long x,int num)
{
	while(x<goal)
	{
		x*=9;
		--num;
	}
	return num<0;
}
void dfs(unsigned long long x,int step)
{
	if(check(x,ans-1-step)) return;
	if(x>=goal) {ans=step;return;}
	int pd[10];
	unsigned long long tmp=x;
	memset(pd,0,sizeof(pd));
	while(tmp)
	{
		pd[tmp%10]=1;
		tmp/=10;
	}
	for(int i=9;i>=2;--i) if(pd[i]) dfs(x*i,step+1);
}
int main()
{
	n=read();
	cin>>x;
	goal=1;
	for(int i=1;i<n;++i) goal*=10;
	dfs(x,0);
	printf("%d\n",(ans==1000?-1:ans));
	return 0;
}
//ore no turn,draw!