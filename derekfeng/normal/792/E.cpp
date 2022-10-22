#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[505];
int m,fc[100000];
ll dp[100000];
bool ok[100000];
int p,ind[100000],ans[100000];
void getind(int x,int &m,int *ind,int *ans){
	m=0;
	for(int l=1;l<=x;){
		int c=x/l,r=x/c;
		if(m>0&&ind[m]==c)ans[m]=min(ans[m],l);
		else ind[++m]=c,ans[m]=l;
		if(x%c==0)ind[++m]=c-1,ans[m]=x/c;
		l=r+1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	getind(a[1],m,fc,ans);
	memset(ok,1,sizeof(ok));
	for(int i=1;i<=n;i++){
		getind(a[i],p,ind,ans);
		int cur=1;
		for(int j=1;j<=m;j++){
			while(cur<=p&&ind[cur]>fc[j])cur++;
			if(cur<=p&&ind[cur]==fc[j]&&ok[j])dp[j]+=ans[cur];
			else ok[j]=0;
		}
	}
	ll ans=1e18;
	for(int i=1;i<=m;i++)if(ok[i])ans=min(ans,dp[i]);
	printf("%lld",ans);
}