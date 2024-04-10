#include <iostream>
#include <cstdio>
#define mod 998244353
using namespace std;
int n,m,a[1000005],b[1000005],now,ans=1;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)scanf("%d",&b[i]);
	now=m;
	for (int i=n;i>=1;i--){
		if (a[i]<b[now]){
			cout<<0<<endl;
			return 0;
		}
		int j=i,k=i;
		while(a[j]>=b[now])j--;
		j++;
		while(k>=j&&a[k]!=b[now])k--;
		if (k<j){
			cout<<0<<endl;
			return 0;
		}
		if (now!=1)ans=1ll*ans*(k-j+1)%mod;
		now--,i=j;
	}
	if (now==0)cout<<ans<<endl;
	else cout<<0<<endl;
	return 0;
}