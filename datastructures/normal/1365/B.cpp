#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[505];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int fg0=0,fg1=0;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		for (int i=1;i<=n;i++){
			int x;
			cin>>x;
			if (x==0)fg0=1;
			else fg1=1;
		}
		if (fg0==1&&fg1==1)puts("YES");
		else{
			int fg=1;
			for (int i=2;i<=n;i++)
				if (a[i]<a[i-1])fg=0;
			if (fg==0)puts("NO");
			else puts("YES");
		}
	}
	return 0;
}