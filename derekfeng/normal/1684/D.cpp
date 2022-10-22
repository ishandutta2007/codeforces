#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		ll sum=0;
		vector<int>ord;
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x),sum+=x;
			ord.push_back(-x+n-i);
		}
		sort(ord.begin(),ord.end());
		for(int i=0;i<k;i++)sum+=ord[i];
		sum-=(ll)k*(k-1)/2;
		printf("%lld\n",sum);
	}
}