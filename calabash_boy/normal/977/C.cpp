#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int n,k;
int a[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	if (k==n){
		printf("1000000000\n");
		return 0;
	}
	if (k==0){
		if (a[0]==1){
			printf("-1\n");
		}else{
			printf("1\n");
		}
		return 0;
	}
	if (a[k]==a[k-1]){
		printf("-1\n");
	}else{
		printf("%d\n",a[k-1]);
	}
	return 0;
}