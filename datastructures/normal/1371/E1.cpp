#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,p,a[2005],tot,ans[2005];
int main(){
	cin>>n>>p;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=2000;i++){
		int mx=0,fg=1;
		for (int j=1;j<=n;j++){
			if (j-max(1,a[j]-i+1)+1<=0)fg=0;
			mx=max(mx,j-(max(1,a[j]-i+1))+1);
		}
		if (mx<p&&fg==1)ans[++tot]=i;
	}
	cout<<tot<<endl;
	for (int i=1;i<=tot;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}