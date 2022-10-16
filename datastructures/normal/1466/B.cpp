#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,a[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		a[n]++;
		for (int i=n-1;i>=1;i--)
			if (a[i]+1<a[i+1])a[i]++;
		int ans=0;
		for (int i=1;i<=n;i++)
			if (i==1||a[i]!=a[i-1])ans++;
		cout<<ans<<endl;
	}
	return 0;
}