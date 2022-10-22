#include<bits/stdc++.h>
using namespace std;
int T,n,num[110];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		sort(num+1,num+n+1);
		for(int i=n;i;i--)printf("%d ",num[i]);puts("");
	}
	return 0;
}