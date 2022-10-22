#include <bits/stdc++.h>
using namespace std;
int k,num,num1=-1;
char res[103][103];
void ansgo(int fr,char c){
	for (int i=1;i<=num;i++)
		res[i][(fr+i-2)%num+1]=c;
}
int main(){
	cin>>k;
	num=1;
	for (;num*num<=k;num++)if(k%num==0){
		num1=k/num;
	}
	num=k/num1;
	if (num1==-1 || num1<5 || num<5){
		puts("-1");return 0;
	}
	for (int i=1;i<=num;i++)for(int j=1;j<=num1;j++) res[i][j]='b';
	ansgo(1,'a');
	ansgo(2,'e');
	ansgo(3,'i');
	ansgo(4,'o');
	ansgo(5,'u');
	for (int i=num+1;i<=num1;i++){ 
		res[1][i]='a',res[2][i]='e',res[3][i]='i',res[4][i]='o',res[5][i]='u';
	} 
	for (int i=1;i<=num;i++)for(int j=1;j<=num1;j++) cout<<res[i][j];
}