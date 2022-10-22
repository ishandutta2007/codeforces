#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=(1<<18),B=18;
ll sum,ans;
int n,a[200004];
bool cmp(int A,int B){
	if(A==-1)return 1;
	if(B==-1)return 0;
	return a[A]<a[B];
}
int best[200004],u[200004],v[200004];
int f[200004];
int dp[N+5][2];
int F(int x){
	return f[x]==x?x:f[x]=F(f[x]);
}
void merge(int *f,int *g){
	int d[4];
	d[0]=f[0],d[1]=f[1],d[2]=g[0],d[3]=g[1];
	if(cmp(d[0],d[1]))swap(d[0],d[1]);if(cmp(d[0],d[2]))swap(d[0],d[2]);if(cmp(d[0],d[3]))swap(d[0],d[3]);
	if(cmp(d[1],d[2]))swap(d[1],d[2]);if(cmp(d[1],d[3]))swap(d[1],d[3]);if(cmp(d[2],d[3]))swap(d[2],d[3]);
	int N=0;
	f[0]=f[1]=-1;
	for(int i=0;i<4;i++)if(d[i]>0){
		bool tmp=1;
		for(int j=0;j<i&&tmp;j++)if(F(d[i])==F(d[j]))tmp=0;
		if(tmp)f[N++]=d[i];
		if(N==2)break;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	a[++n]=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(;;){
		for(int i=0;i<N;i++)dp[i][0]=dp[i][1]=-1;
		for(int i=1;i<=n;i++){
			F(i);
			if(dp[a[i]][0]==-1)dp[a[i]][0]=i;
			else if(f[dp[a[i]][0]]!=f[i])dp[a[i]][1]=i;
		}
		for(int i=0;i<N;i++)
			for(int j=0;j<B;j++)if((1<<j)&i)merge(dp[i],dp[i^(1<<j)]);
		for(int i=1;i<=n;i++)best[i]=-1;
		for(int i=1;i<=n;i++){
			int x=dp[a[i]^(N-1)][0];
			if(x<0)continue;
			if(f[x]!=f[i]){
				if(best[f[i]]<a[i]+a[x]){
					best[f[i]]=a[i]+a[x];
					u[f[i]]=i,v[f[i]]=x;
				}
				continue;
			}
			x=dp[a[i]^(N-1)][1];
			if(x<0)continue;
			if(f[x]!=f[i]){
				if(best[f[i]]<a[i]+a[x]){
					best[f[i]]=a[i]+a[x];
					u[f[i]]=i,v[f[i]]=x;
				}
				continue;
			}
		}
		vector<pair<int,int> >edg;
		for(int i=1;i<=n;i++)if(f[i]==i)
			if(best[i]>0)edg.push_back({u[i],v[i]});
		if(edg.empty())break;
		for(auto x:edg){
			int X=F(x.first),Y=F(x.second);
			if(X!=Y)ans+=a[x.first]+a[x.second],f[X]=Y;
		}
	}
	printf("%I64d",ans-sum);
}