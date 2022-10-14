// Problem: B. Five-In-a-Row
// Contest: Codeforces - Educational Codeforces Round 25
// URL: https://codeforces.com/contest/825/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[13][13];
bool check1(int x,int y)
{
	if(s[x][y]!='X') return 0;
	if(s[x+1][y]!='X') return 0;
	if(s[x+2][y]!='X') return 0;
	if(s[x+3][y]!='X') return 0;
	if(s[x+4][y]!='X') return 0;
	return 1;
}
bool check2(int x,int y)
{
	if(s[x][y]!='X') return 0;
	if(s[x][y+1]!='X') return 0;
	if(s[x][y+2]!='X') return 0;
	if(s[x][y+3]!='X') return 0;
	if(s[x][y+4]!='X') return 0;
	return 1;
}
bool check3(int x,int y)
{
	if(s[x][y]!='X') return 0;
	if(s[x+1][y+1]!='X') return 0;
	if(s[x+2][y+2]!='X') return 0;
	if(s[x+3][y+3]!='X') return 0;
	if(s[x+4][y+4]!='X') return 0;
	return 1;
}
bool check4(int x,int y)
{
	if(s[x][y]!='X') return 0;
	if(s[x-1][y+1]!='X') return 0;
	if(s[x-2][y+2]!='X') return 0;
	if(s[x-3][y+3]!='X') return 0;
	if(s[x-4][y+4]!='X') return 0;
	return 1;
}
void qwq()
{
	puts("YES");
	exit(0);
	return ;
}
signed main()
{

	for(int i=1; i<=10; i++) scanf("%s",s[i]+1);
	for(int i=1; i<=10; i++) for(int j=1; j<=10; j++) if(s[i][j]=='.')
	{
		s[i][j]='X';
		for(int k=1; k<=6; k++) for(int l=1; l<=10; l++)
		{
			if(check1(k,l)) qwq();
			if(check2(l,k)) qwq();
		} 
		for(int k=1; k<=6; k++) for(int l=1; l<=6; l++) if(check3(k,l)) qwq();
		for(int k=5; k<=10; k++) for(int l=1; l<=6; l++) if(check4(k,l)) qwq();
		s[i][j]='.';
	}
	puts("NO");
	return 0;
}