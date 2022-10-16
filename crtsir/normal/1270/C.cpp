#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100003];
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		long long cntplus=0,cntxor=0,k=pow(2,49);
		for(int i=0;i<n;i++)scanf("%lld",a+i),cntplus+=a[i],cntxor^=a[i];
		cout<<"3\n"<<k*2+cntxor<<' '<<(k-(cntplus+cntxor)/2)<<' '<<(k-(cntxor+cntplus)/2)<<endl; 
	}
}