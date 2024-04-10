#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int a[131073];
void solve(){
	int n,k,i;
	scanf("%d%d",&n,&k);
	rep0(i,n){
		a[i]=n-1-i;
	}
	if(k!=n-1){
		rep0(i,n) if(a[i]==k) break;
		if(k!=0){
			swap(a[i],a[n-1]);
			swap(a[a[n-1]],a[a[i]]);
		}
		rep0(i,n){
			if(i<a[i]) printf("%d %d\n",i,a[i]);
		}
		return;
	}
	if(n==4){
		puts("-1");
		return;
	}
	a[1]=3;a[3]=1;
	a[n-1]=n-2;a[n-2]=n-1;
	a[0]=n-4;a[n-4]=0;
	rep0(i,n){
		if(i<a[i]) printf("%d %d\n",i,a[i]);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}