#include<stdio.h>
#define R register int
bool a[3][100002];
int main(){
	int ct=0,n,q,x,y;
	scanf("%d%d",&n,&q);
	for(R i=0;i!=q;i++){
		scanf("%d%d",&x,&y);
		if(a[x][y]==true){
			if(a[3-x][y]==true){
				ct--;
			}
			if(a[3-x][y-1]==true){
				ct--;
			}
			if(a[3-x][y+1]==true){
				ct--;
			}
			a[x][y]=false;
		}else{
			if(a[3-x][y]==true){
				ct++;
			}
			if(a[3-x][y-1]==true){
				ct++;
			}
			if(a[3-x][y+1]==true){
				ct++;
			}
			a[x][y]=true;
		}
		if(ct==0){
			puts("Yes");
		}else{
			puts("No");
		}
	}
	return 0;
}