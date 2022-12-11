#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char buf[10010];
int len;
int main(){
	scanf("%s",buf);
	len = strlen (buf);
	printf("%s",buf);
	for(int i=len-1;i>=0;--i)putchar(buf[i]);
	putchar(32);
	return 0;
}