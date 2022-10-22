#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int o=100;
int T,len;char n[o],c;
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%s",n+1);len=strlen(n+1);
		if(len==2) putchar(n[2]);
		else{
			c='9';
			for(int i=1;i<=len;++i) c=min(c,n[i]);
			putchar(c);
		}
	}
	return 0;
}