#include<bits/stdc++.h>
using namespace std;
int T,n;
char c[12];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%s",c),n=strlen(c);
		int f=0,g=0;
		for(int i=0;i<n;i+=2)f=f*10+c[i]-'0';
		for(int i=1;i<n;i+=2)g=g*10+c[i]-'0';
		printf("%d\n",(long long)(f+1)*(g+1)-2);
	}
}