#include<stdio.h>
#define R register int
int a[500],b[500];
inline void Swap(int&x,int&y){
	int t=x;
	x=y;
	y=t;
}
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=0;i!=n;i++){
		scanf("%d",b+i);
	}
	if((n&1)==1&&a[n>>1]!=b[n>>1]){
		puts("No");
		return;
	}
	for(R i=n-2>>1;i!=-1;i--){
		R l=i,r=n-1-i,j;
		j=r;
		bool tag=false;
		while(l!=-1){
			if(a[i]==b[l]&&a[j]==b[r]){
				Swap(b[i],b[l]);
				Swap(b[j],b[r]);
				tag=true;
				break;
			}else if(a[i]==b[r]&&a[j]==b[l]){
				Swap(b[i],b[r]);
				Swap(b[j],b[l]);
				tag=true;
				break;
			}
			l--;
			r++;
		}
		if(tag==false){
			puts("NO");
			return;
		}
	}
	puts("Yes");
}
int main(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		Solve(); 
	}
	return 0;
}