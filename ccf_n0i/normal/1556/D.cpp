#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j;
int a[10005],a12,a13,a23,o12,o13,o23;
int main(){
	scanf("%d%d",&n,&m);
	puts("and 1 2");fflush(stdout);scanf("%d",&a12);
	puts("and 1 3");fflush(stdout);scanf("%d",&a13);
	puts("and 2 3");fflush(stdout);scanf("%d",&a23);
	puts("or 1 2");fflush(stdout);scanf("%d",&o12);
	puts("or 1 3");fflush(stdout);scanf("%d",&o13);
	puts("or 2 3");fflush(stdout);scanf("%d",&o23);
	for(i=30;i>=0;i--){
		if(((a12>>i)&1)==((o12>>i)&1)){
			a[1]|=(((a12>>i)&1)<<i);
			a[2]|=(((a12>>i)&1)<<i);
			a[3]|=((((a12>>i)&1)^((a13>>i)&1)^((o13>>i)&1))<<i);
			continue;
		}
		if(((a13>>i)&1)==((o13>>i)&1)){
			a[1]|=(((a13>>i)&1)<<i);
			a[3]|=(((a13>>i)&1)<<i);
			a[2]|=((((a13>>i)&1)^((a12>>i)&1)^((o12>>i)&1))<<i);
			continue;
		}
		if(((a23>>i)&1)==((o23>>i)&1)){
			a[2]|=(((a23>>i)&1)<<i);
			a[3]|=(((a23>>i)&1)<<i);
			a[1]|=((((a23>>i)&1)^((a13>>i)&1)^((o13>>i)&1))<<i);
			continue;
		}
		exit(-1);
	}
	for(i=4;i<=n;i++){
		int x,y;
		printf("and 1 %d\n",i);fflush(stdout);scanf("%d",&x);
		printf("or 1 %d\n",i);fflush(stdout);scanf("%d",&y);
		for(j=30;j>=0;j--){
			if((a[1]>>j)&1){
				a[i]|=(((x>>j)&1)<<j);
			}
			else{
				a[i]|=(((y>>j)&1)<<j);
			}
		}
	}
	sort(a+1,a+n+1);
	printf("finish %d\n",a[m]);fflush(stdout);
	return 0;
}