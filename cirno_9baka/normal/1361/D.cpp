#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=500005,M=1000000007;
int n,m,k,i,j,x[N],y[N],tot;
struct str{
	int x,y,a,b;
}p[N];
vector<double> g[N],t[N],dp[N*4];
double ans,s1[N],s2[N];
bool cmp(str a,str b)
{
	if(a.a==b.a)
	{
		if(a.b==b.b)
			return 1ll*a.x*a.x+1ll*a.y*a.y>1ll*b.x*b.x+1ll*b.y*b.y;
		return a.b<b.b;
	}
	return a.a<b.a;
}
double A[N*2],B[N*2];
vector<double> Merge(vector<double> a,vector<double> b)
{
	vector<double> ans;
	for(i=1;i<a.size();++i)
		A[i]=a[i]-a[i-1];
	for(i=1;i<b.size();++i)
		B[i]=b[i]-b[i-1];
	ans.push_back(a[0]+b[0]);
	int l=1,r=1;
	while(l<a.size()&&r<b.size())
		if(A[l]>B[r])
			ans.push_back(A[l++]);
		else
			ans.push_back(B[r++]);
	while(l<a.size())
		ans.push_back(A[l++]);
	while(r<b.size())
		ans.push_back(B[r++]);
	for(i=1;i<ans.size();++i)
		ans[i]+=ans[i-1];
	return ans;
}
void dfs(int i,int l,int r)
{
	if(l==r)
	{
		dp[i]=t[l];
		return;
	}
	int mid=l+r>>1;
	dfs(i<<1,l,mid);
	dfs(i<<1|1,mid+1,r);
	dp[i]=Merge(dp[i<<1],dp[i<<1|1]);
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&x[i],&y[i]);
		if(x[i]!=0||y[i]!=0)
		{
			int a=x[i],b=y[i];
			int g=abs(__gcd(x[i],y[i]));
			a/=g,b/=g;
			p[++k]=(str){x[i],y[i],a,b};
		}
	}
	sort(p+1,p+1+k,cmp);
	for(i=1;i<=k;)
	{
		++tot;
		for(j=i;p[i].a==p[j].a&&p[i].b==p[j].b;++j)
			g[tot].push_back(sqrt(((double)p[j].x)*p[j].x+((double)p[j].y)*p[j].y));
		i=j;
		double s=0;
		g[tot].push_back(0);
		t[tot].push_back(0);
		for(j=0;j<g[tot].size()-1&&j<m;++j)
		{
			t[tot].push_back(s+g[tot][j]*(m-j-1)*(j+1));
			s+=(g[tot][j]-g[tot][j+1])*(m-j-1)*(j+1);
		}
		g[tot].pop_back();
	}
	dfs(1,1,tot);
	if(m<dp[1].size())
		ans=max(ans,dp[1][m]);
	double tmp=0;
	for(i=1;i<=tot;++i)
		tmp+=t[i][t[i].size()-1];
	for(i=1;i<=tot;++i)
		if(m>=n-g[i].size())
		{
			double s=0;
			int y=n-g[i].size();
			g[i].push_back(0);
			for(j=0;j<g[i].size()-1&&j<m;++j)
			{
				s1[j+1]=s;
				s+=(g[i][j]-g[i][j+1])*(m-j-1)*(j+1);
			}
			s=0;
			for(j=g[i].size()-2;j>=0;--j)
			{
				s+=(g[i][j]-g[i][j+1])*((int)g[i].size()-j-2+y)*(m-((int)g[i].size()-j-2+y));
				s2[g[i].size()-j-1]=s;
			}
			for(j=1;j<=m-y;++j)
				ans=max(ans,s1[j]+s2[m-y-j]+(g[i][j-1]-g[i][(int)g[i].size()-(m-y-j)-1])*j*(m-j)+tmp-t[i][t[i].size()-1]);
		}
	printf("%.12lf\n",ans);
}