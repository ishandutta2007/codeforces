#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		vector<int> a(n);
		int sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			sum+=a[i]-1;
		}
		if(sum&1) puts("errorgorn");
		else puts("maomao90");
	}
	return 0;
}