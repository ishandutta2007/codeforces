#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=500005,mod=1000000007;
int T,n,m,a,b,c,d,ans;
int v[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=n;
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		if(n==1){
			puts("0");
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				//(v[j]-v[i])/(j-i)
				int res=0;
				for(int k=1;k<=n;k++)
					if(k!=i&&1ll*(v[k]-v[i])*(j-i)!=1ll*(v[j]-v[i])*(k-i))
						res++;
				ans=min(ans,res);
			}
		printf("%d\n",ans);
	}
	return 0;
}