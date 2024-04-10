#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,num[3],x;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&x),num[x]++;
	if(!num[1])for(int i=1;i<=n;i++)printf("2 ");
	else{
		if(num[2]){
			printf("2 1 ");
			for(int i=1;i<num[2];i++)printf("2 ");
			for(int i=1;i<num[1];i++)printf("1 ");
		}
		else for(int i=1;i<=n;i++)printf("1 ");
	}
	return 0;
}