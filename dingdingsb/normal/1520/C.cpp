#include<bits/stdc++.h>
using namespace std;
signed main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		if(n==2)printf("-1\n");
		else{
			int kk=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					printf("%d ",kk);kk+=2;
					if(kk>n*n)kk=2;
				}
				puts("");
			}
		}
	}
}