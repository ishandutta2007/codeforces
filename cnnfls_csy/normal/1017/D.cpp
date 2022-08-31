#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,q,i,j,k,cnt[4099],ans[4099][105],ql,qr,w[15],lim,s;
string st;
char ss[5];
vector<pair<int,int> > can;
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	fz0k(i,n) scanf("%d",&w[i]);
	fz1(i,m)
	{
		s=0;
		gets(ss);
		fz0k(j,n)
		{
			char c;
			scanf("%c",&c);
			s=s+(c-'0')*(1<<j);
		}
		cnt[s]++;
	}
	fz0k(i,(1<<n))
	{
		s=0;
		fz0k(j,n) if ((i>>j)&1) s+=w[j];
		can.push_back(make_pair(s,i));
	}
	sort(can.begin(),can.end()); 
	fz0k(i,(1<<n))
	{
		k=0;
		fz0g(j,100)
		{
			if (j) ans[i][j]=ans[i][j-1];
			while (k<can.size()&&can[k].first<=j)
			{
				ans[i][j]+=cnt[i^can[k].second];
				k++;
			}
		}
	}
	fz1(i,q)
	{
		s=0;
		gets(ss);
		fz0k(j,n)
		{
			char c;
			scanf("%c",&c);
			s=s+(1-(c-'0'))*(1<<j);
		}
		scanf("%d",&lim);
		printf("%d\n",ans[s][lim]);
	}
	return 0;
}