#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
int T,n,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		k--;
		if(n&1){
			int ans=k+k/(n/2);
			ans=(1+ans)%n;
			printf("%d\n",ans?ans:n);
		}else{
			int ans=(1+k)%n;
			printf("%d\n",ans?ans:n);
		}
	}
	
	return 0;
}