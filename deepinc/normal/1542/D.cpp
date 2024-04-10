#include<bits/stdc++.h>
using namespace std;
#define nw dp[j&1]
#define ls dp[(j&1)^1]
#define mod 998244353
int a[505],ans,dp[2][505]; char s[2];
void add(int&a,int b){a+=b;a=a>=mod?a-mod:a;}
int main(){
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		if(s[0]=='+')scanf("%d",&a[i]);
	}
	for(int i=1,j;i<=n;++i)if(a[i]){
		memset(dp,0,sizeof dp); dp[0][0]=1;
	//	for(j=1;memcpy(nw,ls,sizeof nw),j<=n;++j)if(i^j)for(int k=0;k<j;++k)
//			if(a[j]>a[i]||(a[i]==a[j]&&i<j))add(nw[k],ls[k]);
//			else if(a[j])add(nw[k+1],ls[k]);
//			else if(k||i>j)add(nw[k?k-1:0],ls[k]);
		for(j=1;memcpy(nw,ls,sizeof nw),j<i;++j)for(int k=0;k<j;++k)
			if(a[j]>=a[i])add(nw[k],ls[k]);
			else if(a[j])add(nw[k+1],ls[k]);
			else add(nw[k?k-1:0],ls[k]);
		for(j=i+1;memcpy(nw,ls,sizeof nw),j<=n;++j)for(int k=0;k<j;++k)
			if(a[j]>a[i])add(nw[k],ls[k]);
			else if(a[j])add(nw[k+1],ls[k]);
			else if(k)add(nw[k-1],ls[k]);
		for(int k=0;k<=n;++k)ans=(ans+1ll*ls[k]*a[i])%mod;
	}
	printf("%d",ans);
}