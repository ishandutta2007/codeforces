#include <iostream>
#include <cstdio>
using namespace std;
int t,n,q,a[500005],ans[500005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>q;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		int t=0;
		for (int i=n;i>=1;i--){
			ans[i]=0;
			if (a[i]<=t)ans[i]=1;
			else if (t<q)ans[i]=1,t++;
		}
		for (int i=1;i<=n;i++)putchar(ans[i]+'0');
		puts("");
	}
	return 0;
}