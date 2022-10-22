#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n,m,k,q;
struct zap{
	int x,y,tim;
	bool operator < (const zap a)
	{
		return a.tim>tim;
	}
};
zap tab[250005];
int dp[505][505];
bool ok[505][505];
int daj(int x,int y,int xx,int yy)
{
	return dp[xx][yy]-dp[xx][y-1]-dp[x-1][yy]+dp[x-1][y-1];
}
bool f(int x)
{
	for(int i=1;n>=i;i++)
		for(int j=1;m>=j;j++)
			ok[i][j]=0;
	for(int i=1;q>=i and tab[i].tim<=x;i++)
		ok[tab[i].x][tab[i].y]=1;
	for(int i=1;n>=i;i++)
		for(int j=1;m>=j;j++)
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+ok[i][j];
	for(int i=1;n>=i;i++)
		for(int j=1;m>=j;j++)
			if(i>=k and j>=k and daj(i-k+1,j-k+1,i,j)==k*k)
				return 1;
	return 0;
}
int main()
{	
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;q>=i;i++)
		cin>>tab[i].x>>tab[i].y>>tab[i].tim;
	sort(tab+1,tab+q+1);
	int lewo=0;
	int prawo=1e9+5;
	while(prawo>lewo)
	{
		int mid=(lewo+prawo)/2;
		if(f(mid)==1)
			prawo=mid;
		else
			lewo=mid+1;
	}
	if(lewo==1e9+5)
		cout<<-1;
	else
		cout<<lewo;
    return 0;	
}