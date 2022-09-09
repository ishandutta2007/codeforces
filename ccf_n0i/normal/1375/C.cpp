#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,t,a[300005];
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,n) scanf("%d",&a[i]);
		if(a[1]<a[n]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}