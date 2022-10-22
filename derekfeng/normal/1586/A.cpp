#include<bits/stdc++.h>
using namespace std;
int T,n,a[204];
bool pri[200004];
bool ok[204];
int main(){
	for(int i=2;i<=2e4;i++)if(!pri[i])
		for(int j=i+i;j<=2e4;j+=i)pri[j]=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(ok,1,sizeof(ok));
		int S=0,ans=n;
		for(int i=1;i<=n;i++)S+=a[i];
		if(!pri[S]){
			ans--;
			for(int i=1;i<=n;i++)if(a[i]&1){
				ok[i]=0;break;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)if(ok[i])printf("%d ",i);
		puts("");
	}
}