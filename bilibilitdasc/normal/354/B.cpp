#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n;
char c[25][25];
vector<int> id[25][25];
int cnt;
int tr[2111111][27];
int answer[2111111];
int cnt2;
int tr2[1333333][27];
int answer2[1333333];
bool f[2111111];
void add_str(int x,int y,int v)
{
	id[x][y].pb(v);
	if(x+y<n-1)
	{
		if(!tr[v][c[x][y+1]&31])
		tr[v][c[x][y+1]&31]=++cnt;
		add_str(x,y+1,tr[v][c[x][y+1]&31]);
		if(!tr[v][c[x+1][y]&31])
		tr[v][c[x+1][y]&31]=++cnt;
		add_str(x+1,y,tr[v][c[x+1][y]&31]);
	//	printf("%d->%d,%d\n",v,tr[v][c[x][y+1]&31],tr[v][c[1+x][y]&31]);
	}
}
void add_str2(int x,int y,int v)
{
	if(y!=n-1)
	{
		if(!tr2[v][c[x][y+1]&31])
		tr2[v][c[x][y+1]&31]=++cnt2;
		add_str2(x,y+1,tr2[v][c[x][y+1]&31]);
	}
	if(x!=n-1)
	{
		if(!tr2[v][c[x+1][y]&31])
		tr2[v][c[x+1][y]&31]=++cnt2;
		add_str2(x+1,y,tr2[v][c[x+1][y]&31]);
	}
}
void traverse2(int v,int id,int fl)
{
	bool F=0;
	answer2[v]=-11451419;
	rep1(i,26)
	{
		if(tr2[v][i])
		{
			F=1;
			traverse2(tr2[v][i],i,fl^1);
			answer2[v]=max(answer2[v],answer2[tr2[v][i]]);
		}
	}
	if(!F)
	{
		answer2[v]=0;
	}
	if(fl)
	answer2[v]=(id==1)-(id==2)-answer2[v];
	else
	answer2[v]=(id==2)-(id==1)-answer2[v];
}
void traverse(int v,int id,int fl)
{
//	printf("%d %c %d\n",v,id+96,fl);
	if(f[v])
	return;
	answer[v]=int(0xc0c0c0c0u);
	rep1(i,26)
	{
		if(tr[v][i])
		{
			traverse(tr[v][i],i,fl^1);
			answer[v]=max(answer[v],answer[tr[v][i]]);
		}
	}
	if(fl)
	answer[v]=(id==1)-(id==2)-answer[v];
	else
	answer[v]=(id==2)-(id==1)-answer[v];
//	if(-114<answer[v]&&answer[v]<514)
//	printf("%d?%d\n",v,answer[v]);
}
int main()
{
	scanf("%d",&n);
	rep(i,n) scanf("%s",c[i]);
	memset(answer,0x3f,sizeof(answer));
	add_str(0,0,++cnt);
	rep(i,n)
	{
		cnt2=0;
		int x=i,y=n-1-i;
//		memset(answer2,0,sizeof(answer2));
		memset(tr2,0,sizeof(tr2));
		add_str2(x,y,++cnt2);
		traverse2(1,c[x][y]&31,n&1);
		rep(j,id[x][y].size())
		{
			f[id[x][y][j]]=1;
			answer[id[x][y][j]]=min(answer[id[x][y][j]],answer2[1]);
		}
	//	printf("%d!%d\n",id[x][y],answer[id[x][y]]);
	}
	traverse(1,c[0][0]&31,1);
//	rep1(i,26)
//	{
//		if(tr[1][i])
//		{
//			printf("%d\n",answer[tr[1][i]]);
//		}
//	}
//	printf("%d\n",answer[1]);
	if(answer[1]>0) puts("FIRST");
	else if(answer[1]<0) puts("SECOND");
	else puts("DRAW");
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/