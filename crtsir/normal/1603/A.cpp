#include<bits/stdc++.h>
using namespace std;
int T,n,a[100003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		long long fac=1;
		bool ok=1;
		for(int i=0;i<n;i++){
			if(fac<=1000000000)
				fac=fac*(i+2)/__gcd(fac,1ll*i+2);
			if(a[i]%fac==0)
				ok=0; 
		}
		if(ok)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}