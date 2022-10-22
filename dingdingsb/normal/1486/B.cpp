#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;int x[1010],y[1010];
signed main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&x[i],&y[i]);
		auto work=[&](int *a)->long long{
			sort(a+1,a+1+n);
			if(n&1){
				return 1;
			}
			int X=a[n/2],Y=a[n/2+1],res=0;
			return Y-X+1;
		};
		printf("%lld\n",work(x)*work(y));
	}//cout<<"fuck cccccccccccccccccccccccccccccccf"
}