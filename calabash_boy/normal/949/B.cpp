#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int q;
LL calc(LL n,LL x){
	if (x&1){
		return (x+1)/2;
	}else{
		if (n&1){
			if (x==2){
				return n-n/2+calc(n/2,n/2);
			}else{
				return n-n/2+calc(n/2,x/2-1);
			}
		}else{
			return n/2+calc(n/2,x/2);
		}
	}
}
int main(){
	cin>>n>>q;
	while (q--){
		LL x;
		scanf("%I64d",&x);
		printf("%I64d\n",calc(n,x));
	}
	return 0;
}