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
long long n,m,i,j,l[1000005],r[1000005],cnt[2000005],lst;
vector<long long> all;
vector<pair<long long,long long> > ans;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	fz1(i,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		l[i]=x;r[i]=y;
		l[i]*=2;
		r[i]*=2;
		r[i]++;
		all.push_back(l[i]);
		all.push_back(r[i]);
	}
	sort(all.begin(),all.end());
	fz1(i,n)
	{
		l[i]=upper_bound(all.begin(),all.end(),l[i])-all.begin();
		r[i]=upper_bound(all.begin(),all.end(),r[i])-all.begin();
		cnt[l[i]]++;cnt[r[i]]--;
	}
	lst=-1ll<<50;
	fz1(i,all.size())
	{
		cnt[i]+=cnt[i-1];
		if (cnt[i]<m)
		{
			if (lst!=-1ll<<50)
			{
				ans.push_back(make_pair(lst,all[i-1]));
				lst=-1ll<<50;
			}
		}
		else
		{
			if (lst==-1ll<<50)
			{
				lst=all[i-1];
			}
		}
	}
	printf("%I64d\n",(long long)ans.size());
	fz0k(i,ans.size()) printf("%I64d %I64d\n",ans[i].first/2,(ans[i].second-1)/2);
	return 0;
}