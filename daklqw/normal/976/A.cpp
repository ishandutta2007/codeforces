#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
int n,cnt,cnt1;
int get_int(){
	char t;
	while(t=getchar(),!isdigit(t));
	return t-'0';
}
int main(){
	scanf("%d",&n);
	while(n--)if(get_int())++cnt1;else ++cnt;
	if(cnt1==0){
		putchar('0');
	}else{
		putchar('1');
		while(cnt--)putchar('0');
	}
	putchar(10);
	return 0;
}