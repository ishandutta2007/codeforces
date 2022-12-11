#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) x&-x
using namespace std;
int x,y,num1,num2,ans[40];bool flag;
int main(){
	scanf("%d",&x);y=x;
	while(y){
		if(y&1)flag=1;
		else if(flag)num1++;
		num2++;y>>=1;
	}
	printf("%d\n",2*num1+1);
	for(int i=1;i<=num1+1;i++){
		int y=lowbit(x),num=0;
		x^=(y-1);x++;
		while(y)num++,y>>=1;
		printf("%d ",num-1);
	}
	return 0;
}