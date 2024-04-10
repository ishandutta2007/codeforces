#include<bits/stdc++.h>
using namespace std;
int t,n,a[77];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(n==1){
			puts("0");
			continue;
		}
		int ans=n-2;
		for(int l=1;l<=n;l++)for(int r=l+1;r<=n;r++){
			int tmp=l-1+n-r;
			for(int p=l+1;p<=r-1;p++)
				if((a[r]-a[p])*(p-l)!=(a[p]-a[l])*(r-p))tmp++;
			ans=min(ans,tmp);
		}
		printf("%d\n",ans);
	}
}