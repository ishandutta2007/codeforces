#include<bits/stdc++.h>
using namespace std;
int ct0,ct1;
int main(){
	int n,i,x;
	long long ans=0; 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x>0){
			ans+=x-1;
		}else if(x==0){
			ct0++;
		}else if(x<0){
			ans+=-x-1;
			ct1++;
		}
	}
	ct1%=2;
	if(ct1==1){
		if(ct0>0){
			ans+=ct0;
		}else{
			ans+=2;
		}
	}else{
		ans+=ct0;
	}
	printf("%lld",ans);
	return 0;
}