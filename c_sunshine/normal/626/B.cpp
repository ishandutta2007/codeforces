#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n,c[3];
char s[222];
char f[402][402][402];

char dp(int x,int y,int z)
{
	if(x+y+z==1)
	{
		if(x)return 1;
		if(y)return 2;
		if(z)return 4;
	}
	if(f[x][y][z]!=-1)return f[x][y][z];
	char &r=f[x][y][z];r=0;
	if(x>1)r|=dp(x-1,y,z);
	if(y>1)r|=dp(x,y-1,z);
	if(z>1)r|=dp(x,y,z-1);
	if(x&&y)r|=dp(x-1,y-1,z+1);
	if(x&&z)r|=dp(x-1,y+1,z-1);
	if(y&&z)r|=dp(x+1,y-1,z-1);
	return r;
}

int main()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='B')c[0]++;
		else if(s[i]=='G')c[1]++;
		else if(s[i]=='R')c[2]++;
	memset(f,-1,sizeof(f));
	int ans=dp(c[0],c[1],c[2]);
	if(ans&1)cout<<'B';
	if(ans&2)cout<<'G';
	if(ans&4)cout<<'R';
	cout<<endl;
	return 0;
}