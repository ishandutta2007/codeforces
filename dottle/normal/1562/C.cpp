#include<bits/stdc++.h>
const int N=100050;
using namespace std;

int a[N],t,n;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
		int fl=0;
		for(int i=n/2+1;i<=n;i++)if(a[i]==0){
			printf("%d %d %d %d\n",1,i,1,i-1),fl=1;
			break;
		}
		if(fl)continue;
		for(int i=1;i<=n/2;i++)if(a[i]==0){
			printf("%d %d %d %d\n",i,n,i+1,n),fl=1;
			break;
		}
		if(fl)continue;
		printf("%d %d %d %d\n",1,n-1,2,n);
	}
}