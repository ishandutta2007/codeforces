#include<bits/stdc++.h>
using namespace std;
int t,a,b,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		if(a==1){
			if((n-1)%b==0)puts("Yes");
			else puts("No");
			continue;
		}
		long long now=1;
		bool ok=1;
		while(now<=n){
			if((n-now)%b==0){
				ok=0;
				puts("Yes");
				break;
			}
			now*=a;
		}
		if(ok)puts("No");
	}
}