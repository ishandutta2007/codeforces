#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
pii p[N];
int x[N];
int fmp[N],mp[N];
int main()
{
	int n,m,l,t,a,b,c,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i].fi);
		p[i].se=i;
	}
	sort(p+1,p+1+n);
	for(i=1;i<=n;i++)
	{
		x[i]=p[i].fi,fmp[p[i].se]=i,mp[i]=p[i].se;
		//debug(x[i]);
		//debug(mp[i]);
	}
	while(m--)
	{
		scanf("%d%d",&a,&l);
		//debug(fmp[a]);
		a=fmp[a];
		b=0;
		while(a!=b)
		{
			b=upper_bound(x+1,x+1+n,x[a]+l)-x-1;
			l-=x[b]-x[a];
			//if(a==b)
				//break;
			c=lower_bound(x+1,x+1+n,x[b]-l)-x;
			l-=x[b]-x[c];
			if(b==c)
			{
				a=c;
				break;
			}
			if(c==a)
			{
				t=l/(x[b]-x[a]);
				t=t%2;
				l=l%(x[b]-x[a]);
				if(t==1)
				{
					a=lower_bound(x+1,x+1+n,x[b]-l)-x;
					l-=x[b]-x[a];
				}
				//else b=0;
			}
			else
				a=c;
		}
		//debug(a);
		printf("%d\n",mp[a]);
	}
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
5 5
12 16 19 11 0
2 87
2 16
4 31
3 78
2 8

5 5
0 11 12 16 19
4 87
2 16
4 31
3 78
2 8
*/