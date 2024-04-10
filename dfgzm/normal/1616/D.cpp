#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=500005,mod=1000000007;
int T,n,m,ans,mx;
int v[maxn],vis[maxn];
long long sum[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=n;
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]),vis[i]=0;
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
			v[i]-=m,sum[i]=sum[i-1]+v[i];
		long long mx=-1e18;
		for(int i=1;i<=n;i++){
			if(sum[i]-mx<0)
				mx=-1e18,vis[i]=1,ans--;
			else mx=max(mx,sum[i-1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}