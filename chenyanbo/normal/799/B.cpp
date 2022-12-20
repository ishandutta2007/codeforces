#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>  //ctime   clock()
using namespace std; //  
priority_queue<int,vector<int>,greater<int> > a[4][4];  //10000000
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 220000
int m,n,b[N],p[N],k[N],l,x,y;
//NN
int main()
{
	n=read();  //3e9  //3e9*10 //300...   //ul ll  //u
	for(int i=1; i<=n; ++i)p[i]=read();
	for(int i=1; i<=n; ++i)k[i]=read();
	for(int i=1; i<=n; ++i)b[i]=read();
	for(int i=1; i<=n; ++i)
	{
		if(k[i]<=b[i])a[k[i]][b[i]].push(p[i]); //pop_back()   pop  //push_back()
		else a[b[i]][k[i]].push(p[i]);
	}//kuai kuai ??
	m=read();
	while(m--)  // for
	{
		int c=read(),max=2000000000;  //2e9//max max_
		for(int i=1; i<=c; ++i)if(!a[i][c].empty())//==0
		{
			l=a[i][c].top();
			if(l<max)max=l,x=i,y=c;
		}
		for(int i=c+1; i<=3; ++i)if(!a[c][i].empty())
		{
			l=a[c][i].top();
			if(l<max)max=l,x=c,y=i;  //y=i=c   y=i==c
		}
		//2e9 //2e9
		if(max==2000000000)printf("%d ",-1); //..._  //\n
		else
		{
			a[x][y].pop(); //O2  //bukai man
			printf("%d ",max); //ma  //_max ***
		}
	}
}