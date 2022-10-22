#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
 
using namespace std;
 
int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}
 
const int N=15;
int t;
char s[N][N];
 
int main()
{
	t=read();
	while(t--)
	{
		for(int i=1;i<=9;++i)
			scanf("%s",s[i]+1);
		if(s[1][1]=='9')
			s[1][1]='1';
		else
			s[1][1]++;
			
		if(s[2][4]=='9')
			s[2][4]='1';
		else
			s[2][4]++;
			
		if(s[3][7]=='9')
			s[3][7]='1';
		else
			s[3][7]++;
			
		if(s[4][2]=='9')
			s[4][2]='1';
		else
			s[4][2]++;
			
		if(s[5][5]=='9')
			s[5][5]='1';
		else
			s[5][5]++;
			
		if(s[6][8]=='9')
			s[6][8]='1';
		else
			s[6][8]++;
			
		if(s[7][3]=='9')
			s[7][3]='1';
		else
			s[7][3]++;
			
		if(s[8][6]=='9')
			s[8][6]='1';
		else
			s[8][6]++;
			
		if(s[9][9]=='9')
			s[9][9]='1';
		else
			s[9][9]++;
		for(int i=1;i<=9;++i)
			printf("%s\n",s[i]+1);
	}
	return 0;
}