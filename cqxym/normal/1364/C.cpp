#include<stdio.h>
#include<stack>
using namespace std;
#define R register int
int b[100001],a[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		b[i]=-1;
	}
	stack<int>P;
	int lt=0;
	for(int i=1;i<=n;i++){
		P.push(i);
		for(R j=lt;j!=a[i];j++){
			int t=P.top();
			P.pop();
			b[t]=j;
		}
		lt=a[i];
	}
	for(R i=1;i<=n;i++){
		if(b[i]==-1){
			printf("1000000 ");
		}else{
			printf("%d ",b[i]);
		}
	}
	return 0;
}