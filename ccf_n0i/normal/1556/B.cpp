#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,a[100005],c[2];
long long ans;
long long calc(int x){
	long long s=0;
	int i,c0=(x==0?1:2),c1=3-c0;
	rep(i,n){
		if(a[i]==0){
			s+=abs(i-c0);
			c0+=2;
		}
		else{
			s+=abs(i-c1);
			c1+=2;
		}
	}
	return s/2;
}
void solve(){
	scanf("%d",&n);
	c[0]=c[1]=0;
	int i;
	rep(i,n){
		scanf("%d",&a[i]);
		c[a[i]%=2]++;
	}
	if(abs(c[0]-c[1])>1){
		puts("-1");return;
	}
	ans=1ll<<61;
	if(c[0]>=c[1]) ans=min(ans,calc(0));
	if(c[0]<=c[1]) ans=min(ans,calc(1));
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}