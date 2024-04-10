#include <bits/stdc++.h>
using namespace std;
int a[1003],n,m,ans,x[200004];
int mypow(int x,int t){
	int ans=1,res=x;
	while (t){
		if (t&1){
			ans*=res,ans%=m;t--;continue;
		}
		res*=res,res%=m;t/=2;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>x[i];a[x[i]%m]++;
		if (a[x[i]%m]>1){
			puts("0");return 0;
		}
	}
	ans=1;
	sort (x+1,x+1+n);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			ans*=((x[j]-x[i])%m),ans%=m;
		}
	cout<<ans;
}