#include<bits/stdc++.h>
const int N=1<<17;
using namespace std;

int a[N],n,x,y,t;

int findn(){
	for(int i=1;i+1<=n;i+=2){
		printf("? 1 %d %d %d\n",i,i+1,n-1),fflush(stdout),scanf("%d",&x);
		if(x==n)return i+1;
		if(x==n-1){
			printf("? 1 %d %d %d\n",i+1,i,n-1),fflush(stdout),scanf("%d",&x);
			if(x==n)return i;
		}
	}
	return n;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int p=findn();
		for(int i=1;i<=n;i++){
			if(i==p)a[i]=n;
			else printf("? 2 %d %d %d\n",i,p,1),fflush(stdout),scanf("%d",&a[i]);
		}
		putchar('!');
		for(int i=1;i<=n;i++)
			printf(" %d",a[i]);
		putchar('\n');fflush(stdout);
	}
}