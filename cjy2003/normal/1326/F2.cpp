#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char mp[20][20];
int n,p[20],b[20],cnt[1<<18];
long long dp[1<<18][18],s[19][1<<18],res[1<<18],f[1<<17],ori[19][1<<18];
void work(int m)
{
	int cur=(1<<n)-1;
	for(int i=1,sum=0;i<=m;++i)sum+=p[i],cur^=1<<sum-1;
	for(int i=0;i<1<<n;++i)
		if((n-cnt[i])&1)f[cur]-=res[i];
		else f[cur]+=res[i];
}
void dfs(int w,int rem,int last)
{
	if(!rem)return work(w-1);
	for(int i=0;i<1<<n;++i)ori[w][i]=res[i];
	for(int i=last;i<=rem;++i)
		if(i==rem||i*2<=rem)
		{
			p[w]=i;
			for(int j=0;j<1<<n;++j)res[j]*=s[i][j];
			dfs(w+1,rem-i,i);
			for(int j=0;j<1<<n;++j)res[j]=ori[w][j];
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%s",mp[i]);
	for(int i=1;i<1<<n;++i)cnt[i]=cnt[i>>1]+(i&1);
	for(int i=0;i<n;++i)dp[1<<i][i]=1;
	for(int i=1;i<1<<n;++i)
		for(int j=0;j<n;++j)
			if(i>>j&1)
			{
				s[cnt[i]][i]+=dp[i][j];
				for(int k=0;k<n;++k)
					if(!(i>>k&1)&&mp[j][k]=='1')dp[i|(1<<k)][k]+=dp[i][j];
			}
	for(int i=1;i<=n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<1<<n;++k)
				if(k>>j&1)s[i][k]+=s[i][k^(1<<j)];
	for(int i=0;i<1<<n;++i)res[i]=1;
	dfs(1,n,1);
	for(int i=0;i<1<<n-1;++i)
	{
		int cnt=0,cur=(1<<n)-1;
		for(int j=0,last=0;j<n;++j)if(!(i>>j&1))p[++cnt]=j-last+1,last=j+1;
		sort(p+1,p+1+cnt);
		for(int j=1,sum=0;j<=cnt;++j)sum+=p[j],cur^=1<<sum-1;
		f[i]=f[cur];
	}
	for(int i=0;i<n-1;++i)
		for(int j=0;j<1<<n-1;++j)
			if(j>>i&1)f[j^(1<<i)]-=f[j];
	for(int i=0;i<1<<n-1;++i)printf("%lld ",f[i]);
	return 0;
}