#include<bits/stdc++.h>
using namespace std;
int a[1000],n;
bool ck1(){
	int i;
	for(i=1;i<=n;++i)if(a[i]!=i)return 0;
	return 1;
}
bool ck2(){
	return a[1]==1||a[n]==n;
}
bool ck3(){
	return a[1]==n&&a[n]==1;
}
int main(){
	int T;
	int m,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		if(ck1())puts("0");
		else if(ck2())puts("1");
		else if(ck3())puts("3");
		else puts("2");
	}
	return 0;
}