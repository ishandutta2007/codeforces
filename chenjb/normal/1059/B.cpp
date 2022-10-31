#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
using namespace std;
#define ll long long
int f[2100][2100];
char s[2100][2100];
bool legal(int i,int j)
{
	if (s[i][j]!='#')return 0;
	if (s[i][j+1]!='#')return 0;
	if (s[i][j+2]!='#')return 0;
	if (s[i+1][j]!='#')return 0;
	if (s[i+1][j+2]!='#')return 0;
	if (s[i+2][j]!='#')return 0;
	if (s[i+2][j+1]!='#')return 0;
	if (s[i+2][j+2]!='#')return 0;
	return 1;
}
int main()
{
	int n,m;
	cin>>n>>m;
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%s",s[i]+1);
	rep(i,n-2)rep(j,m-2)
	if (legal(i,j))
	{
		f[i][j]
		=f[i][j+1]=f[i+1][j]
		=f[i][j+2]=f[i+2][j]
		=f[i+1][j+2]=f[i+2][j+1]
		=f[i+2][j+2]=1;
	}

	rep(i,n)rep(j,m)
	if (f[i][j]==1 && s[i][j]=='.')
	{
		puts("NO");
		return 0;
	}
	rep(i,n)rep(j,m)
	if (f[i][j]==0&&s[i][j]=='#')
	{
		puts("NO");
		return 0;
	}
	puts("YES");
}