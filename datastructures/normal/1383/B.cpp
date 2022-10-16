#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int t,n,a[100005]; 
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (register int i=1;i<=n;i++)scanf("%d",&a[i]);
		int fg=3;
		for (register int i=30;i>=0;i--){
			int num=0;
			for (register int j=1;j<=n;j++){
				if (a[j]&(1<<i))num++;
			}
			if (num%2!=0){
				if (((num+1)/2)%2==1||(n-num)%2==1)fg=1;
				else fg=2;
				break;
			}
		}
		if (fg==1)puts("WIN");
		if (fg==2)puts("LOSE");
		if (fg==3)puts("DRAW"); 
	}
	return 0;
}