#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char c[30];
char s[2][30];

void nex(int &x,int &y)
{
	if(x==0)
	{
		if(y==12)
			x++;
		else y++;
	}
	else
	{
		if(y==0)x--;
		else y--;
	}
}

void work(int a,int b)
{
	int t=(b-a-1)/2;
	int x=0,y=12-t;
	s[x][y]=c[a];
	nex(x,y);
	for(int i=(a+1)%27;i!=a;i=(i+1)%27)
		if(i!=b)
		{
			s[x][y]=c[i];
			nex(x,y);
		}
	puts(s[0]);
	puts(s[1]);
}

int main()
{
	scanf("%s",c);
	for(int i=0;i<27;i++)
		for(int j=i+2;j<27;j++)
			if(c[i]==c[j])
			{
				work(i,j);
				return 0;
			}
	puts("Impossible");
	return 0;
}