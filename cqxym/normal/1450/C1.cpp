#include<stdio.h>
#define R register int
char s[300][301];
inline void Solve(){
	int n,x,y,tot=0,ct[2][3]={{0,0,0},{0,0,0}};
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%s",s[i]);
		for(R j=0;j!=n;j++){
			if(s[i][j]!='.'){
				x=s[i][j]=='X'?0:1;
				ct[x][(i+j)%3]++;
				tot++;
			}
		}
	}
	tot/=3;
	for(R i=0;i!=3;i++){
		y=(i+1)%3;
		if(ct[0][i]+ct[1][y]<=tot){
			x=i;
			break;
		}
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=n;j++){
			if(s[i][j]=='X'&&(i+j)%3==x){
				s[i][j]='O';
			}else if(s[i][j]=='O'&&(i+j)%3==y){
				s[i][j]='X';
			}
			putchar(s[i][j]);
		}
		puts("");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}