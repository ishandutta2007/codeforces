#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int T,n,ans=0,a[2003];
bool cmp(int x,int y){
	return x%2<y%2;
}
int main(){
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(gcd(a[i],2*a[j])>1)ans++;
		cout<<ans<<"\n";
	}
}