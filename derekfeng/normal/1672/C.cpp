#include<bits/stdc++.h>
using namespace std;
int t,a[200004];
int n,ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans+=(i>1&&a[i]==a[i-1]);
		if(ans<=1){puts("0");continue;}
		int ret=0;
		for(int i=2;i<=n;i++)if(a[i]==a[i-1]){
			if(ans<=1)break;
			ans--,ret++;
			int cur=a[i-1]<1e6?1e9:a[i-1]-1;
			if(a[i]==a[i+1])ans--;
			if(a[i+1]==a[i+2])ans--;
			a[i]=a[i+1]=cur;
			ans++;
		}
		printf("%d\n",ret);
	}
}