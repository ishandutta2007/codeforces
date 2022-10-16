#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
long long x,y,k,ans,need;
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0,need=0;
		scanf("%lld%lld%lld",&x,&y,&k);
		need=y*k+k-1;
		ans += need/(x-1);
		if(need % (x-1))ans++;
		ans+=k;
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
5
2 1 5
42 13 24
12 11 12
1000000000 1000000000 1000000000
2 1000000000 1000000000
*/