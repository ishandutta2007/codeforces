#include<cstdio>
char c;
int main(){
	for(;~(c=getchar());){
	  if(c<91&&c>64)c+=32;
	  if(c!='a'&&c!='o'&&c!='y'&&c!='e'&&c!='u'&&c!='i'&&c!='\n')putchar('.'),putchar(c);
	}return 0;
}