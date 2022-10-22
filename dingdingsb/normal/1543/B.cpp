#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
int t,n,a[N];
signed main(){
	scanf("%d",&t);
	while(t--){
		int sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		int rest=sum%n;
		printf("%lld\n",rest*(n-rest));
	}
}