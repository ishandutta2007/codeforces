#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		int sum=0;
		for (int i=1,x;i<=n;++i){
			scanf("%d",&x);
			if (x>2048) continue; 
			sum+=x;
		}
		if (sum<2048) puts("NO"); else puts("YES");
	}
	return 0;
}