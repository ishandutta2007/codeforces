#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,ans;
	long long n,i,t;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=9;++i){
			t=0;
			while(t*10LL+i<=n){
				++ans;
				t=t*10LL+i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}