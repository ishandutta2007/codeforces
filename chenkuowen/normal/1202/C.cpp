#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+2e5;
char s[MAX_N];
int sum[MAX_N],n;
int mi[2][MAX_N],mx[2][MAX_N];
pair<int,int> solve(){
	for(int t=0;t<2;++t)
		for(int i=0;i<=n+1;++i)
			mi[t][i]=1e9,mx[t][i]=-1e9;
	mi[0][0]=mx[0][0]=sum[0];
	for(int i=1;i<=n;++i){
		mi[0][i]=min(mi[0][i-1],sum[i]);
		mx[0][i]=max(mx[0][i-1],sum[i]);
	}
	for(int i=n;i>=0;--i){
		mi[1][i]=min(mi[1][i+1],sum[i]);
		mx[1][i]=max(mx[1][i+1],sum[i]);
	}
//	for(int i=1;i<=n;++i) printf("|%d|",sum[i]); puts("");
	int ret=1e9;
	for(int i=1;i<=n;++i){
		int mx0=max(max(mx[0][i-1],mx[1][i]-1),sum[i-1]-1);
		int mi0=min(min(mi[0][i-1],mi[1][i]-1),sum[i-1]-1);
		int mx1=max(max(mx[0][i-1],mx[1][i]+1),sum[i-1]+1);
		int mi1=min(min(mi[0][i-1],mi[1][i]+1),sum[i-1]+1);
		ret=min(ret,min(mx0-mi0+1,mx1-mi1+1));
//		printf("[%d %d %d %d]",mi0,mx0,mi1,mx1);
	}
//	printf("<%d %d>",mx[0][n]-mi[0][n]+1,ret); puts("");
	return make_pair(mx[0][n]-mi[0][n]+1,ret);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1); 
		for(int i=1;i<=n;++i)
			if(s[i]=='D') sum[i]=sum[i-1]+1;
			else if(s[i]=='A') sum[i]=sum[i-1]-1;
			else sum[i]=sum[i-1];
		pair<ll,ll> a=solve();
		for(int i=1;i<=n;++i)
			if(s[i]=='W') sum[i]=sum[i-1]+1;
			else if(s[i]=='S') sum[i]=sum[i-1]-1;
			else sum[i]=sum[i-1];
		pair<ll,ll> b=solve();
		printf("%lld\n",min(min(a.first*b.second,a.second*b.first)
			,a.first*b.first));
	}
	return 0;
}