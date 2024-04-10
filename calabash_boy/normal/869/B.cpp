#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b;
int ans=1;
int main(){
	cin>>a>>b;
	if (b-a>10){
		b=a/10*10+10+b%10;
	}
	for (LL i=a+1;i<=b;i++){
		ans =ans*(i%10);
		ans%=10;
	}
	cout<<ans<<endl;
	return 0;
}