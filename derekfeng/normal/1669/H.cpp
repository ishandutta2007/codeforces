#include<bits/stdc++.h>
using namespace std;
int n,k,num[31];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		memset(num,0,sizeof(num));
		scanf("%d%d",&n,&k);
		for(int i=0,x;i<n;i++){
			scanf("%d",&x);
			for(int j=0;j<31;j++)
				num[j]+=((x>>j)&1);
		}
		int ans=0;
		for(int i=30;~i;i--){
			if(num[i]<n){
				int rem=n-num[i];
				if(rem<=k)
					num[i]=n,k-=rem;
			}
			if(num[i]==n)ans|=(1<<i);
		}
		printf("%d\n",ans);
	}
}