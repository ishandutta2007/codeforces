#include<bits/stdc++.h>
using namespace std;
int a[100005];
void work(int x,int y,int z){
	printf("%d %d %d\n",x,y,z);
	int t=a[x]^a[y]^a[z];
	a[x]=a[y]=a[z]=t;
}
int main(){
	int n,i,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s^=a[i];
	}
	if(n&1){
		printf("YES\n%d\n",n-1);
		for(i=1;i+i<=n-1;++i)work(1,i+i,i+i+1);
		for(i=1;i+i<=n-1;++i)work(1,i+i,i+i+1);
	}
	else{
		if(s)puts("NO");
		else{
			puts("YES");
			printf("%d\n",n-2);
			for(i=1;i+i<=n-2;++i)work(1,i+i+1,i+i+2);
			for(i=1;i+i<=n-2;++i)work(1,i+i+1,i+i+2);
		}
	}
	return 0;
}