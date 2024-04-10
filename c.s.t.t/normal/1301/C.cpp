#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m,res;
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		res=n*(n+1)/2,n-=m,m++;
		res-=(n%m)*(n/m+1)*(n/m+2)/2+(m-(n%m))*(n/m)*(n/m+1)/2;
		printf("%I64d\n",res);
	}
}