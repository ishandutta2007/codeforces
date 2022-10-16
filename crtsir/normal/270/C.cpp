#include<bits/stdc++.h>
using namespace std;
long long ans,n;
long long madeans(long long x){
	long long a=0;
	x=sqrt(x-1)+1;
	while(pow(2,a)<x)a++;
	return max(a,1ll);
}
int main(){
	cin>>n;
	while(n--){
		long long x,y;
		cin>>x>>y;
		ans=max(ans,x+madeans(y));
	}
	cout<<ans;
}