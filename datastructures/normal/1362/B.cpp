#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[2005],b[2005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
		sort(b+1,b+1+n);
		int fg=0;
		for (int i=1;i<=2000;i++){
			for (int j=1;j<=n;j++)a[j]=b[j]^i;
			sort(a+1,a+1+n);
			int diff=0;
			for (int j=1;j<=n;j++)
				if (a[j]!=b[j])diff=1;
			if (diff==0){
				cout<<i<<endl;
				fg=1;
				break;
			} 
		}
		if (fg==0)puts("-1");
	}
	return 0;
}