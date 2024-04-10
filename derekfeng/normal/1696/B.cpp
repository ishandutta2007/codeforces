#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,ans=0;scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>0&&a[i-1]==0)ans++;
		}
		printf("%d\n",min(ans,2));
	}
}