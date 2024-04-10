#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
int n,a[N<<1];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++)scanf("%d",&a[i]);
	sort(a+1,a+(n<<1)+1);
	LL ans=1e18;
	for(int i=1,mi,ma;i<=n+1;i++){
		if(i==1)mi=a[i+n];else mi=a[1];
		if(i==n+1)ma=a[i-1];else ma=a[n<<1];
		ans=min(ans,(LL)(ma-mi)*(a[i+n-1]-a[i]));
	}
	printf("%lld\n",ans);
	return 0;
}