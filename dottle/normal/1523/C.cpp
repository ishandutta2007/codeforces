#include<bits/stdc++.h>
const int N=2005;
using namespace std;

int n,t,x,b[N],top;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x),top=0;
		b[top++]=1;
		printf("%d\n",1);
		for(int i=2;i<=n;i++){
			scanf("%d",&x);
			if(x==1)b[top++]=1;
			else{
				while(b[top-1]!=x-1)top--;
				b[top-1]++;
			}
			printf("%d",b[0]);
			for(int i=1;i<top;i++)printf(".%d",b[i]);
			putchar('\n');
		}
	}
}