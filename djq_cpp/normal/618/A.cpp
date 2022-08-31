#include <cstdio>
#include <stack>
int stack[10005],top=-1;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		stack[++top]=1;
		while(stack[top]==stack[top-1])
		stack[--top]++;
	}
	for(int k=0;k<=top;k++)printf("%d ",stack[k]);
	return 0;
}