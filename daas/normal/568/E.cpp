#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,top,a[MAXN],val[MAXN],pd[MAXN],A[MAXN];
vector<int> dp[MAXN],pre[MAXN];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	m=read();
	for(int i=1;i<=m;++i) val[i]=read();
	sort(val+1,val+m+1);
	dp[0].push_back(0);
	for(int i=1;i<=n;++i)
		if(a[i]==-1)
		{
			for(int j=top,cur=m;j>=0;--j)
			{
				while(cur-1>=1 && val[cur-1]>dp[j][dp[j].size()-1]) --cur;
				if(val[cur]>dp[j][dp[j].size()-1] && (j==top || val[cur]<dp[j+1][dp[j+1].size()-1]))
				{
					if(j==top)
					{
						dp[++top].push_back(val[cur]);
						pre[top].push_back(dp[top-1].size()-1);
					}
					else
					{
						dp[j+1].push_back(val[cur]);
						pre[j+1].push_back(dp[j].size()-1);
					}
				}
			}
		}
		else
		{
			if(!top || a[i]>dp[top][dp[top].size()-1])
			{
				dp[++top].push_back(a[i]);
				pre[top].push_back(dp[top-1].size()-1);
			}
			else
			{
				int l=1,r=top,zone=0;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(dp[mid][dp[mid].size()-1]>=a[i]) zone=mid,r=mid-1;
					else l=mid+1;
				}
				if(a[i]<dp[zone][dp[zone].size()-1])
				{
					dp[zone].push_back(a[i]);
					pre[zone].push_back(dp[zone-1].size()-1);
				}
			}
		}
	for(int i=top,P=dp[top].size()-1;i>=1;--i)
	{
		A[i]=dp[i][P];
		P=pre[i][P];
	}
	for(int i=1,cur=1,cur2=1;i<=n && cur<=top;++i)
		if(a[i]==-1)
		{
			while(val[cur2]<A[cur]) ++cur2;
			if(cur2<=m && val[cur2]==A[cur]) a[i]=val[cur2],pd[cur2]=1,++cur;
		}
		else
		{
			if(a[i]==A[cur]) ++cur;
		}
	for(int i=1,cur=1;i<=n;++i)
		if(a[i]==-1)
		{
			while(pd[cur]) ++cur;
			a[i]=val[cur];
			++cur;
		}
	//for(int i=1;i<=top;++i) cout<<A[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	putchar('\n');
	return 0;
}
//ore no turn,draw!