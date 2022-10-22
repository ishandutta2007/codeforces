#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n,s,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&s,&n,&k);
		if(s==k){
			puts("YES");
			continue;
		}
		if(k>s){
			puts("NO");
			continue;
		}
		ll m=s+k,a,b;
		ll num=s-s%k;
		b=s-num+1;
		a=k-b;
		if((s/k)%2==1)m-=b;
		else m-=a;
		if(2*n+1>m)puts("YES");
		else puts("NO");
	}
}