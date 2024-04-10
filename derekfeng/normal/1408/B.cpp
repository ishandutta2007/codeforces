#include<bits/stdc++.h>
using namespace std;
int T,n,K,a[104];
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&K);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>1&&a[i]==a[i-1]){
				i--,n--;
			}
		}
		n--,K--;
		if(n>0&&K==0){
			puts("-1");
			continue;
		}
		if(n==0){
			puts("1");
			continue;
		}
		printf("%d\n",(n+K-1)/K);
	}
}