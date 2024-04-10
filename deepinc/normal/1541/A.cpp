#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t; while(t--){
		int n; scanf("%d",&n);
		if(n==1)puts("1");
		else if(n&1){
			printf("3 1 2 ");
			for(int i=4;i<=n;++i)printf("%d ",i^1); puts("");
		}else{
			for(int i=1;i<=n;++i)printf("%d ",(i+1^1)-1);puts("");
		}
	}
}