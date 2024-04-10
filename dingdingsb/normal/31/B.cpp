#include<bits/stdc++.h>
using namespace std;
char str[200+10];
int w[200+10],pos=0;
int main(){
	scanf("%s",str+1);
	int len=strlen(str+1);
	for(int i=1;i<=len;i++)
		if(str[i]=='@')
			w[++pos]=i;
	if(w[1]==1||w[pos]==len||pos==0)printf("No solution"),exit(0);
	for(int i=1;i<pos;i++)
		if(w[i+1]-w[i]<=2)
			printf("No solution"),exit(0);
	w[0]=-1;w[pos+1]=len+2;
	int st=1;
	for(int i=1;i<=pos;i++){
		if(i!=1)printf(",");
		for(;st<=w[i+1]-2;st++)
			printf("%c",str[st]);
	}
}