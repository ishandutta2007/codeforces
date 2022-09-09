#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int t,n,i,a[105],s;
int main(){
	scanf("%d",&t);
	while(t--){
		s=0;scanf("%d",&n);
		rep(i,n){
			scanf("%d",&a[i]);
			s+=a[i];
		}
		sort(a+1,a+n+1);
		if((s&1)||(a[n]>s-a[n])){
			puts("T");
		}
		else{
			puts("HL");
		}
	}
	return 0;
}