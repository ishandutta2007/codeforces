#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[105],mx,sum;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		mx=0,sum=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			mx=max(mx,a[i]);
			sum+=a[i];
		}
		if (mx*2>sum)puts("T");
		else{
			if (sum&1)puts("T");
			else puts("HL");
		}
	}
	return 0;
}