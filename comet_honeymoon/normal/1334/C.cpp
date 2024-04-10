#include<bits/stdc++.h>
using namespace std;

int T,N;
long long A[300005],B[300005],C[300005]; 

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		long long ans=0,d=1e18;
		for(int i=0;i<N;i++) scanf("%lld%lld",&A[i],&B[i]);
		for(int i=0;i<N;i++) ans+=max(0LL,A[i]-B[(i-1+N)%N]),d=min(d,A[i]-max(0LL,A[i]-B[(i-1+N)%N]));
		printf("%lld\n",ans+d);
	} 
}