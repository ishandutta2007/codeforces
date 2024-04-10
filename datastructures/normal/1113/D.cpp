#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,fg;
char s[10005],t[10005];
inline int check(){
	int nowflag=0;
	for (register int i=1;i<=n/2;i++){
		if (t[i]!=s[i])nowflag=1;
		if (t[i]!=t[n-i+1])return 0;
	}
	return nowflag;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n/2;i++){
		int tot=0;
		for (register int j=i+1;j<=n;j++)
			t[++tot]=s[j];
		for (register int j=1;j<=n;j++)
			t[++tot]=s[j];
		if (check())fg=1;
	}
	if (fg==1){
		puts("1");
		return 0;
	}
	for (int i=1;i<=n/2;i++){
		for (register int j=1;j<=n;j++)
			t[j]=s[j];
		for (register int j=1;j<=i;j++)
			swap(t[j],t[n-i+j]);
		if (check())fg=1;
	}
	if (fg==1){
		puts("2");
		return 0;
	}
	else{
		puts("Impossible");
		return 0;
	}
	return 0;
}