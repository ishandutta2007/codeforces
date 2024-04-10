#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1000100;
const int E[4][2]={{1,1},{1,-1},{-1,-1},{-1,1}};
int K,Q,cnt[MX];

void Solve(int t)
{
	int u=0,d=0,l=0,r=0;
	Fr(i,1,Q)
	{
		int c=cnt[i];
		c-=max(0,-i-u-l+1);
		c-=max(0,r-i-u+1);
		c-=max(0,-i+d-l+1);
		c-=max(0,r-i+d+1);
		
		if(t==1)
		{
			if(c>0&&u==1-i)--u,--c;
			if(c>0&&d==i-1)++d,--c;
			if(c>0&&l==1-i)--l,--c;
			if(c>0&&r==i-1)++r,--c;
		}
		else if(t==2)
		{
			if(c>0&&u==1-i)--u,--c;
			if(c>0&&l==1-i)--l,--c;
			if(c>0&&d==i-1)++d,--c;
			if(c>0&&r==i-1)++r,--c;
		}
		else
		{
			if(c>0&&l==1-i)--l,--c;
			if(c>0&&u==1-i)--u,--c;
			if(c>0&&d==i-1)++d,--c;
			if(c>0&&r==i-1)++r,--c;
		}
		if(c)return;
	}
	int n=d-u+1,m=r-l+1;
	if(n*m!=K)return;
	printf("%d %d\n%d %d\n",n,m,1-u,1-l);
	exit(0);
}

int main()
{
	scanf("%d",&K);
	Fr(i,1,K)
	{
		int x;
		scanf("%d",&x);
		++cnt[x],Q=max(Q,x);
	}
	Solve(1);
	Solve(2);
	Solve(3);
	printf("-1\n");
	return 0;
}