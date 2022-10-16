#include<bits/stdc++.h> 
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--) 
using namespace std;
int T,n,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		for(int i=3;i*i<=2*n-1;i+=2){
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}