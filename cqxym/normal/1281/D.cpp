#include<stdio.h>
#define R register int
#define I inline bool
#define E return
char s[60][60];
int r,c;
I CheckP(){
	for(R i=0;i!=r;i++){
		for(R j=0;j!=c;j++){
			if(s[i][j]=='A'){
				E false;
			}
		}
	}
	E true;
}
I CheckA0(){
	for(R i=0;i!=r;i++){
		for(R j=0;j!=c;j++){
			if(s[i][j]=='P'){
				E false;
			}
		}
	}
	E true;
}
I CheckA1(){
	bool tag=true;
	for(R i=0;i!=c;i++){
		if(s[0][i]=='P'){
			tag=false;
		}
	}
	if(tag==true){
		E true;
	}
	tag=true;
	for(R i=0;i!=c;i++){
		if(s[r-1][i]=='P'){
			tag=false;
		}
	}
	if(tag==true){
		E true;
	}
	tag=true;
	for(R i=0;i!=r;i++){
		if(s[i][0]=='P'){
			tag=false;
		}
	}
	if(tag==true){
		E true;
	}
	tag=true;
	for(R i=0;i!=r;i++){
		if(s[i][c-1]=='P'){
			tag=false;
		}
	}
	E tag;
}
I CheckA2(){
	if(s[0][0]=='A'||s[0][c-1]=='A'||s[r-1][0]=='A'||s[r-1][c-1]=='A'){
		E true;
	}
	bool tag;
	for(R i=1;i<r-1;i++){
		tag=true;
		for(R j=0;j!=c;j++){
			if(s[i][j]=='P'){
				tag=false;
			}
		}
		if(tag==true){
			E true;
		}
	}
	for(R i=1;i<c-1;i++){
		tag=true;
		for(R j=0;j!=r;j++){
			if(s[j][i]=='P'){
				tag=false;
			}
		}
		if(tag==true){
			E true;
		}
	}
	E false;
}
I CheckA3(){
	for(R i=1;i<c-1;i++){
		if(s[0][i]=='A'){
			E true;
		}
	}
	for(R i=1;i<c-1;i++){
		if(s[r-1][i]=='A'){
			E true;
		}
	}
	for(R i=1;i<r-1;i++){
		if(s[i][c-1]=='A'){
			E true;
		}
	}
	for(R i=1;i<r-1;i++){
		if(s[i][0]=='A'){
			E true;
		}
	}
	E false;
}
inline void Solve(){
	scanf("%d%d",&r,&c);
	for(R i=0;i!=r;i++){
		getchar();
		for(R j=0;j!=c;j++){
			s[i][j]=getchar();
		}
	}
	if(CheckP()==true){
		puts("MORTAL");
	}else if(CheckA0()==true){
		puts("0");
	}else if(CheckA1()==true){
		puts("1");
	}else if(CheckA2()==true){
		puts("2");
	}else if(CheckA3()==true){
		puts("3");
	}else{
		puts("4");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
    E 0;
}