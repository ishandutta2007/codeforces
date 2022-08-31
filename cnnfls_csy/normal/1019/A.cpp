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
long long n,m,i,j,ans=1ll<<55,idx[3005],num[3005],cnt;
string st;
vector<long long> seq[3005];
long long calc(long long x)
{
	long long i,sum=0,s=0;
	fz0g(i,m) seq[i].clear();
	fz1(i,n)
	{
		if (idx[i]!=1)
		{
			seq[idx[i]].push_back(num[i]);
		}
	}
	fz(i,2,m)
	{
		stable_sort(seq[i].begin(),seq[i].end());
		reverse(seq[i].begin(),seq[i].end());
		while (seq[i].size()>=x)
		{
			s++;
			sum+=seq[i].back();
			seq[i].pop_back();
		}
		ff(seq[i],it) seq[0].push_back(*it);
	}
	x-=cnt+s;
	stable_sort(seq[0].begin(),seq[0].end());
	fz0k(i,x) sum+=seq[0][i];
	return sum;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	fz1(i,n)
	{
		scanf("%I64d%I64d",&idx[i],&num[i]);
		if (idx[i]==1) cnt++;
	}
	for (i=max(1ll,cnt);i<=n;i++)
	{
		ans=min(ans,calc(i));
	}
	cout<<ans<<endl;
	return 0;
}