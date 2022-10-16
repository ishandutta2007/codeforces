#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int t,n,k,x[105],y[105],fg;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		fg=0;
		for (int i=1;i<=n;i++)cin>>x[i]>>y[i];
		for (int i=1;i<=n;i++){
			int mx=1;
			for (int j=1;j<=n;j++)
				if (abs(x[i]-x[j])+abs(y[i]-y[j])>k)mx=0;
			if (mx==1)fg=1;
		}
		if (fg==1)puts("1");
		else puts("-1");
	}
	return 0;
}