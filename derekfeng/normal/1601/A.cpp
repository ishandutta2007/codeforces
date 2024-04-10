#include<bits/stdc++.h>
using namespace std;
int n,a[200005],T,num[31],x;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			for(int i=0;i<31;i++)num[i]+=(x>>i)&1;
		}
		for(int i=1;i<=n;i++){
			bool ok=1;
			for(int j=0;j<31;j++)if(num[j]%i!=0)ok=0;
			if(ok)printf("%d ",i);
		}
		puts("");
	}
}