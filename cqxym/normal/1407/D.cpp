#include<stdio.h>
#define R register int
#define N 300001
int a[N],b[N],h[N],f[N];
inline void Min(int&a,int&b){
	a=a<b?a:b;
}
int main(){
	int n,ct1=0,ct2=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",h+i);
		f[i]=f[i-1];
		while(ct1!=0&&h[a[ct1]]>h[i]){
			ct1--;
			if(ct1!=0){
				Min(f[i],f[a[ct1]]);
			}
		}
		while(ct2!=0&&h[b[ct2]]<h[i]){
			ct2--;
			if(ct2!=0){
				Min(f[i],f[b[ct2]]);
			}
		}
		if(ct1!=0&&h[a[ct1]]==h[i]){
			ct1--;
		}
		ct1++;
		a[ct1]=i;
		if(ct2!=0&&h[b[ct2]]==h[i]){
			ct2--;
		}
		ct2++;
		b[ct2]=i;
		f[i]++;
	}
	printf("%d",f[n]-1);
	return 0;
}