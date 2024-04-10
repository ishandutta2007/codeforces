#include<cstdio>
int a;
int main(){
	scanf("%d",&a);
	switch(a%4){
	  case 0:printf("1 A");break;
	  case 1:printf("0 A");break;
	  case 2:printf("1 B");break;
	  case 3:printf("2 A");break;
	}return 0;
}