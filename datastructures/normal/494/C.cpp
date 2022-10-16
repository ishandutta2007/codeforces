#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxv 10000
using namespace std;
int n,m,a[100005],lg_num[100005],st[100005][25];
struct node{
	int l,r,val;
	double p;
}c[5005];
bool cmp(node a,node b){
	if (a.l==b.l)return a.r>b.r;
	return a.l<b.l;
}
int ask(int l,int r){
	int len=lg_num[r-l+1];
	return max(st[l][len],st[r-(1<<len)+1][len]);
}
int tot,sta[5005];
int totm,u[5005],v[5005],first[5005],nxt[5005];
void add_edge(int a,int b){
	int i=++totm;
	u[i]=a,v[i]=b;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
int mx,d[5005];
double p[5005],f[5005][10005],ans;
double dp_a[10005],dp_b[10005],sum_a[10005],sum_b[10005],dp_c[10005];
void dp(){
	sum_a[0]=dp_a[0],sum_b[0]=dp_b[0];
	for (int i=1;i<=maxv;i++)sum_a[i]=sum_a[i-1]+dp_a[i],sum_b[i]=sum_b[i-1]+dp_b[i];
	for (int i=0;i<=maxv;i++){
		if (i>0)dp_c[i]=dp_a[i]*sum_b[i-1]+dp_b[i]*sum_a[i-1]+dp_a[i]*dp_b[i];
		else dp_c[i]=dp_a[i]*dp_b[i];
	}
	return;
}
void dfs(int now){
	f[now][d[now]]=1;
	for (int i=first[now];i;i=nxt[i]){
		dfs(v[i]);
		for (int j=0;j<=maxv;j++)dp_a[j]=f[now][j],dp_b[j]=f[v[i]][j];
		dp();
		for (int j=0;j<=maxv;j++)f[now][j]=dp_c[j];
	}
	for (int i=maxv;i>=0;i--)f[now][i]=(1-p[now])*f[now][i]+p[now]*f[now][i-1];
	return;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)st[i][0]=a[i];
	for (int i=1;i<=n;i++)
		while((1<<(lg_num[i]+1))<=i)lg_num[i]++;
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for (int i=1;i<=m;i++){
		cin>>c[i].l>>c[i].r>>c[i].p;
		c[i].val=ask(c[i].l,c[i].r);
	}
	sort(c+1,c+1+m,cmp);
	for (int i=1;i<=m;i++){
		while(tot>0&&c[sta[tot]].r<c[i].l)tot--;
		if (tot==0)add_edge(0,i);
		else add_edge(sta[tot],i);
		sta[++tot]=i;
	}
	for (int i=1;i<=n;i++)mx=max(mx,a[i]);
	for (int i=1;i<=m;i++)d[i]=max(0,c[i].val-(mx-5000)),p[i]=c[i].p;
	d[0]=mx-(mx-5000),p[0]=0.0000000;
	dfs(0);
	for (int i=0;i<=maxv;i++)ans+=(i+(mx-5000))*f[0][i];
	printf("%.9lf\n",ans);
	return 0;
}