#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,k1,k2,mx1=0,mx2=0; scanf("%d%d%d",&n,&k1,&k2);
		for(int i=1;i<=k1;++i){
			int x; scanf("%d",&x);
			mx1=max(mx1,x);
		}
		for(int i=1;i<=k2;++i){
			int x; scanf("%d",&x);
			mx2=max(mx2,x);
		}
		if(mx1>mx2) puts("YES");
		else puts("NO");
	}
	return 0;
}