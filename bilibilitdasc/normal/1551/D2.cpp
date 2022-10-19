#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a);i<=(b);++i)
#define perk(i,a,b) for(int i=(a);i>=(b);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n,m,k,cnt,res;
int clr[105][105];
char ch[105][105];
const int dx[6]={-1,0,0,1,1,2};
const int dy[6]={0,-1,1,-1,1,0};
bool valid(int i,int j)
{
	return 0<=i&&0<=j&&i<n&&j<m;
}
int chk(int n,int m,int k)
{
	int r=(n*m)>>1,tp=0;
	if(n&1)
	{
		k-=(m>>1);
		r-=(m>>1);
		tp=1;
	}
	else if(m&1)
	{
		r-=(n>>1);
		tp=2;
	}
	if(k&1) return -1;
	else if(0<=k&&k<=r) return tp;
	else return -1;
}
void Q()
{
	scanf("%d%d%d",&n,&m,&k);
	cnt=0;memset(clr,0,sizeof(clr));memset(ch,0,sizeof(ch));
	if((res=chk(n,m,k))==-1)
	{
		printf("NO\n");
		return ;
	}
	printf("YES\n");
	if(res==0)
	{
		for(int i=0;i<n;++++i) for(int j=0;j<m;++++j)
		{
			if(k>0)
			{
				clr[i][j]=clr[i][j+1]=++cnt;clr[i+1][j]=clr[i+1][j+1]=++cnt;
				----k;
			}
			else
			{
				clr[i][j]=clr[i+1][j]=++cnt;clr[i][j+1]=clr[i+1][j+1]=++cnt;
			}
		}
	}
	else if(res==1)
	{
		--n;
		for(int i=0;i<m;++++i)
		{
			clr[n][i]=clr[n][i+1]=++cnt;
			--k;
		}
		for(int i=0;i<n;++++i) for(int j=0;j<m;++++j)
		{
			if(k>0)
			{
				clr[i][j]=clr[i][j+1]=++cnt;clr[i+1][j]=clr[i+1][j+1]=++cnt;
				----k;
			}
			else
			{
				clr[i][j]=clr[i+1][j]=++cnt;clr[i][j+1]=clr[i+1][j+1]=++cnt;
			}
		}
		++n;
	}
	else
	{
		--m;
		for(int i=0;i<n;++++i)
		{
			clr[i][m]=clr[i+1][m]=++cnt;
		}
		for(int i=0;i<n;++++i) for(int j=0;j<m;++++j)
		{
			if(k>0)
			{
				clr[i][j]=clr[i][j+1]=++cnt;clr[i+1][j]=clr[i+1][j+1]=++cnt;
				----k;
			}
			else
			{
				clr[i][j]=clr[i+1][j]=++cnt;clr[i][j+1]=clr[i+1][j+1]=++cnt;
			}
		}
		++m;
	}
	rep(i,n) rep(j,m)
	{
		if(ch[i][j]==0)
		{
			if(clr[i][j]==clr[i+1][j])
			{
				for(ch[i][j]='a';;++ch[i][j])
				{
					bool flag=0;
					ch[i+1][j]=ch[i][j];
					rep(kkk,6)
					{
						int x=i+dx[kkk],y=j+dy[kkk];
						if(valid(x,y)) if(ch[x][y]==ch[i][j]) flag=1;
					}
					if(!flag)
					break;
				}
			}
			else
			{
				for(ch[i][j]='a';;++ch[i][j])
				{
					bool flag=0;
					ch[i][j+1]=ch[i][j];
					rep(kkk,6)
					{
						int x=i+dy[kkk],y=j+dx[kkk];
						if(valid(x,y)) if(ch[x][y]==ch[i][j]) flag=1;
					}
					if(!flag)
					break;
				}
			}
		}
	}
	rep(i,n)
	printf("%s\n",ch[i]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	Q();
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/