#include<stdio.h>
#include<algorithm>
#define R register int
int a[2000],b[2000],c[2000],n;
inline void Init(int *S){
	for(R i=0;i!=n;i++){
		scanf("%d",S+i);
	}
	std::sort(S,S+n);
}
int main(){
	int m,x,s;
	scanf("%d%d",&n,&m);
	Init(a);
	Init(b);
	s=m;
	for(R i=0;i!=n;i++){
		x=b[i]-a[0]+m;
		x=x<m?x:x-m;
		if(x>=s){
			continue;
		}
		for(R j=0;j!=n;j++){
			c[j]=(a[j]+x)%m;
		}
		std::sort(c,c+n);
		bool f=false;
		for(R j=0;j!=n;j++){
			if(c[j]!=b[j]){
				f=true;
				break;
			}
		}
		if(f==false){
			s=x;
		}
	}
	printf("%d",s);
	return 0;
}