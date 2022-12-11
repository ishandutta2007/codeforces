#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;
#define mod 1000000007
unordered_map<long long,int>dp[51][51];
struct lsh
{
	int va,id;
	bool operator < (const lsh&a)const
	{
		return va<a.va;
	}
}d1[100],d2[100];
struct col
{
	int cnt,fp,id;
	bool operator < (const col &a)const
	{
		if(cnt!=a.cnt)return cnt>a.cnt;
		return fp<a.fp;
	}
}p[100];
vector<pair<int,int> >a[100];
int n,k,w[100],jl1,jl2,x[100],y[100],ans,jc[100010],dy[100];
long long bk[100];
bool bj[100][100];
int main()
{
//	freopen("Bdata.txt","r",stdin);
	scanf("%d %d",&n,&k);
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=1ll*jc[i-1]*i%mod;
	for(int i=1;i<=k;++i)
	{
		scanf("%d %d %d",&d1[i].va,&d2[i].va,&w[i]);
		--w[i];
		if(w[i]<0)w[i]+=mod;
		d1[i].id=i;
		d2[i].id=i;
	}
	sort(d1+1,d1+1+k);
	sort(d2+1,d2+1+k);
//	for(int i=1;i<=k;++i)
//		printf("%d %d\n",d1[i].va,d1[i].id);
	for(int i=1;i<=k;++i)
	{
		if(d1[i].va!=d1[i-1].va)++jl1,p[jl1].fp=0x3f3f3f3f,p[jl1].id=jl1;
		x[d1[i].id]=jl1;
		++p[jl1].cnt;
	}
	for(int i=1;i<=k;++i)
	{
		if(d2[i].va!=d2[i-1].va)++jl2;
		y[d2[i].id]=jl2;
		p[x[d2[i].id]].fp=min(p[x[d2[i].id]].fp,jl2);
	}
	sort(p+1,p+1+jl1);
	for(int i=1;i<=jl1;++i)
		dy[p[i].id]=i;
	for(int i=1;i<=k;++i)
		x[i]=dy[x[i]];
//	for(int i=1;i<=k;++i)
//		printf("%d %d\n",x[i],y[i]);
	for(int i=1;i<=k;++i)
		a[x[i]].push_back(make_pair(y[i],w[i]));
	for(int i=jl1;i>=1;--i)
	{
		bk[i]=bk[i+1];
		for(auto j:a[i])
			bk[i]|=1ll<<j.first;
	}
/*	for(int i=1;i<=jl1;++i)
	{
		for(int j=1;j<=jl2;++j)
			printf("%d ",a[i][j]);
		printf("\n");
	}*/
	dp[0][0][0]=1;
	for(int i=0;i<jl1;++i)
		for(int j=0;j<=i;++j)
			for(auto it:dp[i][j])
			{
				(dp[i+1][j][it.first&bk[i+1]]+=it.second)%=mod;
				for(auto l:a[i+1])
				{
					if((it.first>>l.first)&1)continue;
					(dp[i+1][j+1][(it.first|(1ll<<l.first))&bk[i+1]]+=1ll*it.second*l.second%mod)%=mod;
				}
			}
	for(int i=0;i<=jl1;++i)
	{
		int sum=0;
		for(auto j:dp[jl1][i])
			(sum+=j.second)%=mod;
		(ans+=1ll*jc[n-i]*sum%mod)%=mod;
	}
	printf("%d",ans);
	return 0;
}