#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int t,n,m,a[105];
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		int s=0;
		for (int i=1;i<=n;i++)cin>>a[i],s+=a[i];
		if (s==m)puts("YES");
		else puts("NO"); 
	}
	return 0;
}