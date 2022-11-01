#include<stdio.h>
#define R register int
char s[200000],t[200000],g[199999];
int n;
inline bool Com(){
	for(R i=0;i!=n;i++){
		if(s[i]<t[i]){
			return true;
		}else if(s[i]>t[i]){
			return false;
		}
	}
	return true;
}
int main(){
	int k,x;
	scanf("%d%d\n",&n,&k);
	for(R i=0;i!=k;i++){
		g[i]=getchar();
		s[i]=t[i]=g[i];
	}
	for(R i=k;i!=n;i++){
		s[i]=getchar();
		t[i]=g[i%k];
	}
	if(Com()==false){
		g[k-1]++;
		for(R i=k-1;i!=-1;i--){
			x=g[i]-'0';
			if(x>9){
				g[i]=x%10+'0';
				g[i-1]+=x/10;
			}else{
				break;
			}
		}
		for(R i=0;i!=n;i++){
			t[i]=g[i%k];
		}
	}
	printf("%d\n",n);
	for(R i=0;i!=n;i++){
		printf("%c",t[i]);
	}
	return 0;
}