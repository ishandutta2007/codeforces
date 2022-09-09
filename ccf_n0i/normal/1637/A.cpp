#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int a[11111];
void solve(){
	int n,i;
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);
	rep(i,n-1){
		if(a[i]>a[i+1]){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}