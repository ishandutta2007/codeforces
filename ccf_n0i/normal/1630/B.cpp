#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int a[231073],c[231073];
int X,Y;
void solve(){
	int n,k,i;
	scanf("%d%d",&n,&k);X=1;Y=n;
	rep(i,n) c[i]=0;
	rep(i,n) scanf("%d",a+i);
	rep(i,n) c[a[i]]++;
	int sum=0,j=1;
	rep(i,n){
		sum+=c[i];
		while(sum-c[j]-(n-(sum-c[j]))>=k){
			sum-=c[j];
			j++;
		}
		if(sum-(n-sum)>=k&&(i-j+1<Y-X+1)){
			X=j;
			Y=i;
		}
	}
	printf("%d %d\n",X,Y);
	int lst=0,cur=0;
	rep(i,n){
		if(k==1){
			printf("%d %d\n",i,n);
			return;
		}
		if(X<=a[i]&&a[i]<=Y) cur++; else cur--;
		if(cur==1){
			k--;cur=0;
			printf("%d %d\n",lst+1,i);lst=i;
		}
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