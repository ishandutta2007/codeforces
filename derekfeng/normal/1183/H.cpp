#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e12;
int n,lst[26];
ll f[104][104],K,sum,ans;
char s[104];
ll g[104];
int main(){
	scanf("%d%I64d%s",&n,&K,s+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		s[i]-='a';
		for(int j=0;j<i;j++)for(int k=0;k<=j;k++)
			if(lst[s[i]]<=j&&f[j][k]){
				f[i][k+1]+=f[j][k];
				f[i][k+1]=min(f[i][k+1],inf);			
			}
		lst[s[i]]=i;
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)if(f[i][j])g[j]+=f[i][j],sum+=f[i][j];
	if(sum<K)puts("-1");
	else{
		for(int i=n,j=0;K>0;i--,j++){
			if(K<=g[i])ans+=K*j,K=0;
			else K-=g[i],ans+=g[i]*j;
		}
		printf("%I64d",ans);
	}
}