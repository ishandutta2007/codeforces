#include<cstdio>
#define swap(x,y) x^=y^=x^=y
int ggg(int a,int b){
	return b?ggg(b,a%b):a;	
}

int main(){
	int a[2],c,i=0;
	scanf("%d%d%d",a,a+1,&c);
	while(1){
		if(c==0)break;
		if(c>=ggg(a[i&1],c)){
			c-=ggg(a[i&1],c);
			i++;
		}
		else break;
	}
	printf("%d",!(i&1));
}