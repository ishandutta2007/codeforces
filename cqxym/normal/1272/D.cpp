#include<stdio.h>
int a[200000],f[200000][2];
inline void Max(int &x,int y){
	x=x>y?x:y;
}
int main(){
	int n,s=0;
	scanf("%d",&n);
	for(register int i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	f[0][0]=1;
	if(a[1]>a[0]){
		f[1][0]=2;
	}else{
		f[1][0]=1;
	}
	for(register int i=2;i!=n;i++){
		if(a[i]>a[i-1]){
			f[i][0]=f[i-1][0]+1;
			Max(f[i][1],f[i-1][1]+1);
		}else{
			f[i][0]=1;
		}
		if(a[i]>a[i-2]){
			Max(f[i][1],f[i-2][0]+1);
		}
	}
	for(register int i=0;i!=n;i++){
		Max(s,f[i][0]);
		Max(s,f[i][1]);
	}
	printf("%d",s);
	return 0;
}