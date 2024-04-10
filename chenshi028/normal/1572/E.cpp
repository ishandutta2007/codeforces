#include<cstdio>
#include<iostream>
#include<utility>
#include<cmath>
using namespace std;
const int o=210;
int n,K,x[o],y[o],s[o][o];long long ans,bnd;pair<int,long long> f[o][o];
inline long long S(int i,int j,int k)
{return abs(x[i]*1ll*y[j]-y[i]*1ll*x[j]+x[j]*1ll*y[k]-y[j]*1ll*x[k]+x[k]*1ll*y[i]-y[k]*1ll*x[i]);}
pair<int,long long> z(pair<int,long long> pr){if(pr.second>=bnd) return make_pair(pr.first+1,0);return pr;}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]);
	for(int i=n;i;--i) for(int j=i+2;j<=n;++j) s[i][j]=s[i+1][j]+S(i,i+1,j);
	for(long long l=1,r=8e16,md;l<r;ans=l){
		bnd=md=(l+r>>1)+1;
		for(int i=n;i;--i) for(int j=i+2,k;j<=n;++j) for(f[i][j]=z(make_pair(0,s[i][j])),k=i+1;k<j;++k)
			f[i][j]=max(f[i][j],z(make_pair(f[i][k].first+f[k][j].first,f[i][k].second+f[k][j].second+S(i,j,k))));
		if(f[1][n].first>K) l=md;
		else r=md-1;
	}
	printf("%lld",ans);
	return 0;
}