#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int t,n,a[300005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		if (a[1]>a[n])puts("NO");
		else puts("YES");
	}
	return 0;
}