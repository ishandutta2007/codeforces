#include<stdio.h>
#define R register int
int a[200],b[200];
char s[200];
bool c[500][200];
int main(){
	int n,ans=0,u;
	scanf("%d\n",&n);
	for(R i=0;i<n;i++){
		scanf("%c",&s[i]);
	}
	for(R i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	for(R i=0;i<n;i++){
		if(s[i]=='1'){
			c[0][i]=true;
		}
		R j;
		for(j=0;j<b[i];j++){
			c[j][i]=c[0][i];
		}
		if(c[j-1][i]==false){
			c[j][i]=true;
		}
		while(j<300){
			for(R k=j;k-j<a[i];k++){
				c[k][i]=c[j][i];
			}
			j+=a[i];
			if(c[j-a[i]][i]==false){
				c[j][i]=true;
			}
		}
	}
	for(R i=0;i<300;i++){
		u=0;
		for(R j=0;j<n;j++){
			if(c[i][j]==true){
				u++;
			}
		}
		if(u>ans){
			ans=u;
		}
	}
	printf("%d",ans);
	return 0;
}