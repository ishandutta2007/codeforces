#include<stdio.h>
#define R register int
bool b[200002][2][2];
int tp[200002][2];
int Read(){
	char c=getchar();
	return c^48;
}
void Solve(){
	int n;
	scanf("%d\n",&n);
	for(R i=1;i<=n;i++){
		tp[i][0]=Read();
		b[i][0][0]=b[i][1][1]=b[i][1][0]=b[i][0][1]=false;
	}
	getchar();
	for(R i=1;i<=n;i++){
		tp[i][1]=Read();
	}
	b[1][0][0]=true;
	for(R i=1;i<=n;i++){
		if(tp[i][0]<3){
			if(b[i][0][0]==true){
				b[i+1][0][0]=true;
			}
		}else{
			if(b[i][0][0]==true){
				b[i][1][1]=true;
			}
			if(b[i][0][1]==true){
				b[i+1][0][0]=true;
			}
		}
		if(tp[i][1]<3){
			if(b[i][1][0]==true){
				b[i+1][1][0]=true;
			}
		}else{
			if(b[i][1][0]==true){
				b[i][0][1]=true;
			}
			if(b[i][1][1]==true){
				b[i+1][1][0]=true;
			}
		}
		if(tp[i][0]<3){
			if(b[i][0][0]==true){
				b[i+1][0][0]=true;
			}
		}else{
			if(b[i][0][0]==true){
				b[i][1][1]=true;
			}
			if(b[i][0][1]==true){
				b[i+1][0][0]=true;
			}
		}
	}
	if((tp[n][1]<3&&b[n][1][0]==true)||(tp[n][1]>2&&b[n][1][1]==true)){
		puts("YES");
	}else{
		puts("NO");
	}
}
int main(){
	int q;
	scanf("%d",&q);
	for(R i=0;i<q;i++){
		Solve();
	}
	return 0;
}