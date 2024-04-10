#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int t,n,a[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int fg=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if (i>1&&a[i]<a[i-1])fg=1;
		}
		if (fg==1)puts("YES");
		else puts("NO");
	}
	return 0;
}