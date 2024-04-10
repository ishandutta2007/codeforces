#include<queue>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<map>
#include<bitset>
/*
DO NOT HACK ME!!!!!!!
PLEASE!!!!!!!!
ORZ!!!!!!!!!!!
CYJIAN AK IOI!!!!!!!!
I WILL BECAME NEWBIE!!!!!!!1
SORRY!!!!!!!!!!1
BUT
I
M
U
S
T
S
T
O
P
D
O
I
N
G
T
H
I
S
!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
SO!!!!!!!!!!!11

don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
don't HACK ME!!!!!!!!!!!!!!!!!!!
*/
using namespace std;
#define re register int
#define ahhhh qwq!!!!
int cnt,fx[4][2]= {{-1,0},{1,0},{0,-1},{0,1}},n,m,val[10],v[10],CYJian,tot,pp;
char s[1005][1005];
queue<int>p[10],q[10],t[10];
inline void solve(re u,queue<int>&x,queue<int>&y,queue<int>&t)
{
	while(!x.empty())
	{
		re nx=x.front(),ny=y.front(),nt=t.front();
		if(nt>=CYJian*v[u]) break;
		x.pop(),y.pop(),t.pop();
		for(re i=0;i<4;i++)
		{
			re tx=nx+fx[i][0],ty=ny+fx[i][1],tt=nt+1;
			if(tx<1||ty<1||tx>n||ty>m) continue;
			if(s[tx][ty]=='.') s[tx][ty]=u+48,tot--,val[u]++,x.push(tx),y.push(ty),t.push(tt);
		}
	}
}
int main()
{
	cin>>n>>m>>pp;
	for(re i=1;i<=pp;i++) cin>>v[i];
	for(re i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(re j=1;j<=m;j++)
		{
			if(isdigit(s[i][j]))
			{
				re x=s[i][j]-48;
				p[x].push(j);q[x].push(i);t[x].push(0);val[x]++;
			}
			if(s[i][j]=='.') tot++;
		}
	}
	cnt=0;
	while(tot)
	{
		CYJian++;
		for(re i=1;i<=pp;i++)
		if(!q[i].empty()) solve(i,q[i],p[i],t[i]);
		else cnt++;
		if(cnt==pp) break;
		else cnt=0;
	}
	for(re i=1;i<=pp;i++)
	printf("%d ",val[i]);
	return 0;
}