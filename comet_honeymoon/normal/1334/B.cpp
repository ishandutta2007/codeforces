#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,N,X;long long p[100005];
bool cmp(long long a,long long b){return a>b;}

signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&X);
		for(int i=1;i<=N;i++) scanf("%lld",&p[i]);
		sort(p+1,p+N+1,cmp);
		int ans=0;
		for(int i=1;i<=N;i++){
			p[i]+=p[i-1];
			if(p[i]>=1LL*X*i) ans=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}