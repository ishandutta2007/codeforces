#include<bits/stdc++.h>
using namespace std;
int A,B,K;
int main(){
	scanf("%d%d%d",&A,&B,&K);
	if(K==0){
		puts("Yes");
		for(int i=1;i<=B;i++)putchar('1');
		for(int i=1;i<=A;i++)putchar('0');
		puts("");
		for(int i=1;i<=B;i++)putchar('1');
		for(int i=1;i<=A;i++)putchar('0');
		return 0;
	}
	if(K>=A+B-1||B==1||A==0){
		puts("No");
		return 0;
	}
	puts("Yes");
	if(K<=A){
		for(int i=1;i<=B;i++)putchar('1');
		for(int i=1;i<=A;i++)putchar('0');
		puts("");
		for(int i=1;i<B;i++)putchar('1');
		for(int i=1;i<=K;i++)putchar('0');
		putchar('1');
		for(int i=K;i<A;i++)putchar('0');
	}else{
		for(int i=1;i<=B;i++)putchar('1');
		for(int i=1;i<=A;i++)putchar('0');
		puts("");
		for(int i=1;i<=B-1-K+A;i++)putchar('1');
		putchar('0');
		for(int i=1;i<=K-A;i++)putchar('1');
		for(int i=1;i<A;i++)putchar('0');
		putchar('1');
	}
}