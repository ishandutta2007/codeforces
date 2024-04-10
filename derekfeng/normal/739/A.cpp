#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
	scanf("%d%d",&n,&m),ans=n;
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		ans=min(ans,r-l+1);
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)printf("%d ",i%ans);
}