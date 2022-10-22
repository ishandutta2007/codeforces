#include<bits/stdc++.h>
using namespace std;
int t,n,a[103];
int main(){
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		while(n--){
			int x;scanf("%d",&x);
			a[abs(x)]++;
		}
		int ans=0;
		for(int i=0;i<=100;i++)if(a[i]>0){
			ans++;
			if(i>0&&a[i]>1)ans++;
		}
		printf("%d\n",ans);
	}
}